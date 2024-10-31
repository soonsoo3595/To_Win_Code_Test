#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

struct Edge
{
	int u, v, weight;
};

vector<Edge> adj;
long long dist[504];		// 최단 경로

int N, M;

bool Func()
{
	fill(dist, dist + 504, INF);

	dist[1] = 0;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < adj.size(); j++)
		{
			int u = adj[j].u;
			int v = adj[j].v;
			long long weight = adj[j].weight;

			if (dist[u] != INF && dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
			}
		}
	}

	for (int j = 0; j < adj.size(); j++)
	{
		int u = adj[j].u;
		int v = adj[j].v;
		long long weight = adj[j].weight;

		if (dist[u] != INF && dist[v] > dist[u] + weight)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		adj.push_back({ A, B, C });
	}

	if (Func())
	{
		cout << -1 << '\n';
	}
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == INF)
				cout << -1 << '\n';
			else
				cout << dist[i] << '\n';
		}
	}
}
