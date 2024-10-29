#include <bits/stdc++.h>

using namespace std;

int V, E, K;
int u, v, w;

struct Edge
{
    int node, weight;
};

vector<Edge> graph[20004];
int dist[20004];

void Dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, K });

    while (!pq.empty())
    {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for (Edge& edge : graph[curNode])
        {
            int nextNode = edge.node;
            int nextDist = curDist + edge.weight;

            if (nextDist < dist[nextNode])
            {
                dist[nextNode] = nextDist;
                pq.push({ nextDist, nextNode });
            }
        }

    }
}

int main()
{
    cin >> V >> E >> K;

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;

        graph[u].push_back({ v, w });
    }

    fill(dist, dist + 20004, INT_MAX);
    dist[K] = 0;

    Dijkstra();

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}

