#include <bits/stdc++.h>
using namespace std;

struct Edge
{
	int u, v, weight;
};

vector<Edge> adj;
int dist[504];		// 최단 경로

int TC;
int N, M, W;

bool Func()
{
	fill(dist, dist + 504, 987654321);

	dist[1] = 0;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < adj.size(); j++)
		{
			int u = adj[j].u;
			int v = adj[j].v;
			int weight = adj[j].weight;

			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
			}
		}
	}

	for (int j = 0; j < adj.size(); j++)
	{
		int u = adj[j].u;
		int v = adj[j].v;
		int weight = adj[j].weight;

		if (dist[v] > dist[u] + weight)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	cin >> TC;

	while (TC--)
	{
		cin >> N >> M >> W;

		adj.clear();

		for (int i = 0; i < M; i++)
		{
			int u, v, weight;
			cin >> u >> v >> weight;
			adj.push_back({ u, v, weight });
			adj.push_back({ v, u, weight });
		}

		for (int i = 0; i < W; i++)
		{
			int u, v, weight;
			cin >> u >> v >> weight;
			adj.push_back({ u, v, -weight });
		}

		if (Func())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}	

}
