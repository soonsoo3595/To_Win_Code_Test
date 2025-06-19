#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int v;
	int w;
};

int N, E, v1, v2;
vector<Edge> adj[804];
int dist[804];
const int MAX = 987654321;

void Input() 
{
	cin >> N >> E;

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({b, c});
		adj[b].push_back({ a, c });
	}

	cin >> v1 >> v2;
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
	vector<int> start_1 = dijkstra(1);
	vector<int> start_v1 = dijkstra(v1);
	vector<int> start_v2 = dijkstra(v2);

	long long a = (long long)start_1[v1] + start_v1[v2] + start_v2[N];
	long long b = (long long)start_1[v2] + start_v2[v1] + start_v1[N];
	long long answer = min(a, b);

	if (answer >= MAX)
	{
		cout << -1;
	}
	else
	{
		cout << answer;
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
