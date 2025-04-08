#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> adj[104];
int visited[104];
int min_kebbin = INT_MAX;
vector<int> answer;

void Input()
{
	cin >> N >> M;

	while (M--)
	{
		int A, B;
		cin >> A >> B;

		adj[A].push_back(B);
		adj[B].push_back(A);
	}
}

void Solve()
{
	for (int i = 1; i <= N; i++)
	{
		queue<int> q;
		q.push(i);
		visited[i] = 1;

		while (!q.empty())
		{
			int here = q.front();
			q.pop();

			for (int there : adj[here])
			{
				if (visited[there])
					continue;

				q.push(there);
				visited[there] = visited[here] + 1;
			}
		}

		int kebbin = 0;

		for (int i = 1; i <= N; i++)
		{
			kebbin += (visited[i] - 1);
		}

		if (kebbin < min_kebbin)
		{
			min_kebbin = kebbin;
			answer.clear();
			answer.push_back(i);
		}
		else if (kebbin == min_kebbin)
		{
			answer.push_back(i);
		}

		fill(visited, visited + 104, 0);
	}

	cout << answer[0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}