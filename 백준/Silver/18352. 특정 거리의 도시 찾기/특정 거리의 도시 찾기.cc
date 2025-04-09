#include <bits/stdc++.h>
using namespace std;

int N, M, K, X;
vector<int> adj[300004];
int dist[300004];
vector<int> answer;

void Input()
{
	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;

		adj[A].push_back(B);
	}
}

void Solve()
{
	fill(dist, dist + 300004, INT_MAX);

	queue<pair<int, int>> q;
	q.push({ X, 0 });
	dist[X] = 0;

	while (!q.empty())
	{
		int curNode = q.front().first;
		int curDist = q.front().second;
		q.pop();

		for (int next : adj[curNode])
		{
			if (curDist + 1 < dist[next])
			{
				q.push({ next, curDist + 1 });
				dist[next] = curDist + 1;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == K)
		{
			answer.push_back(i);
		}
	}

	if (answer.empty())
	{
		cout << -1;
	}
	else
	{
		for (int node : answer)
		{
			cout << node << '\n';
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