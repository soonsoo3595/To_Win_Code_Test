#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int v;
	int w;
};

int N, M, s, e;
vector<Edge> adj[1004];
int dist[1004];
const int MAX = 987654321;

void Input() 
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int A, B, W;
		cin >> A >> B >> W;

		adj[A].push_back({ B,W });
	}

	cin >> s >> e;
}

void Solve()
{
	fill(dist, dist + 1004, MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, s });

	while (!pq.empty())
	{
		int curNode = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if (dist[curNode] < curDist) continue;

		for (const auto& edge : adj[curNode])
		{
			int nextNode = edge.v;
			int nextDist = curDist + edge.w;

			if (nextDist < dist[nextNode])
			{
				dist[nextNode] = nextDist;
				pq.push({ nextDist, nextNode });
			}
		}
	}

	cout << dist[e];
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}
