#include <bits/stdc++.h>
using namespace std;

int V, E, K;

struct Edge
{
	int v;
	int cost;
};
vector<Edge> adj[20004];
int dist[20004];

constexpr int DIST_MAX = 987654321;

void Input()
{
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}
}

void Solve()
{
	fill(dist, dist + 20004, DIST_MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, K });
	dist[K] = 0;

	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		for (auto& edge : adj[curNode])
		{
			int nextNode = edge.v;
			int nextDist = curDist + edge.cost;

			if (nextDist < dist[nextNode])
			{
				pq.push({ nextDist, nextNode });
				dist[nextNode] = nextDist;
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == DIST_MAX)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << dist[i] << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}