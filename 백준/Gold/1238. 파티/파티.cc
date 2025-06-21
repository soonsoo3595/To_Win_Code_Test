#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int v;
	int w;
};

int N, E, X;
vector<Edge> adj[1004];
const int MAX = 987654321;

void Input() 
{
	cin >> N >> E >> X;

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({b, c});
	}
}

vector<int> dijkstra(int start)
{
	vector<int> dist(N + 1, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int curNode = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if (curDist > dist[curNode])
		{
			continue;
		}

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

	return dist;
}

void Solve()
{
	int answer = 0;

	for (int i = 1; i <= N; i++)
	{
		vector<int> itoX = dijkstra(i);
		vector<int> Xtoi = dijkstra(X);

		int distance = itoX[X] + Xtoi[i];
		answer = max(answer, distance);
	}

	cout << answer;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}
