#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[104][104];
int dp[104][104];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void Input()
{
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		for (int j = 0; j < M; j++)
		{
			arr[i][j] = input[j] - '0';
		}
	}
}

void Solve()
{
	fill(&dp[0][0], &dp[103][104], INT_MAX);

	deque<pair<int, int>> dq;
	dq.push_front({ 0, 0 });
	dp[0][0] = 0;

	while (!dq.empty())
	{
		int y = dq.front().first;
		int x = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			int count = dp[y][x] + arr[ny][nx];

			if (count < dp[ny][nx])
			{
				dp[ny][nx] = count;

				if (arr[ny][nx] == 1)
				{
					dq.push_back({ ny, nx });
				}
				else
				{
					dq.push_front({ ny, nx });
				}
			}
		}
	}

	cout << dp[N - 1][M - 1];
}

int main()
{
	Input();

	Solve();
}
