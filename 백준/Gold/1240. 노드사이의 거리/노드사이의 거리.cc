#include <bits/stdc++.h>
using namespace std;

int N, M;
pair<int, int> p;

struct Edge
{
    int v, cost;
};

vector<Edge> adj[1004];
int dist[1004];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;

        adj[u].push_back({ v, cost });
        adj[v].push_back({ u, cost });
    }

    while (M--)
    {
        int u, v;
        cin >> u >> v;

        fill(dist, dist + 1004, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, u});
        dist[u] = 0;

        while (!pq.empty())
        {
            int curNode = pq.top().second;
            int curDist = pq.top().first;
            pq.pop();

            if (curNode == v)
            {
                cout << curDist << '\n';
                break;
            }

            for (auto& p : adj[curNode])
            {
                int nextNode = p.v;
                int nextDist = curDist + p.cost;

                if (nextDist < dist[nextNode])
                {
                    dist[nextNode] = nextDist;
                    pq.push({ nextDist, nextNode });
                }
            }
        }

    }

    return 0;
}