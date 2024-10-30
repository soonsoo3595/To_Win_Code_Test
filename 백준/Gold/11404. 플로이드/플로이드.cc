#include <bits/stdc++.h>

using namespace std;

int n, m;
struct Edge
{
    int v, cost;
};

vector<Edge> adj[104];
int dist[104][104];

void Dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, start });
    dist[start][start] = 0;

    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();

        for (auto& edge : adj[curNode])
        {
            int nextNode = edge.v;
            int nextCost = edge.cost + curCost;

            if (nextCost < dist[start][nextNode])
            {
                dist[start][nextNode] = nextCost;
                pq.push({ nextCost, nextNode });
            }
        }
    }
}

int main()
{
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;

        adj[u].push_back({ v, cost });
    }

    for (int i = 0; i < 104; i++)
    {
        for (int j = 0; j < 104; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        Dijkstra(i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INT_MAX)
                cout << 0 << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
 