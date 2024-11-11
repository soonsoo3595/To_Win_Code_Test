#include <bits/stdc++.h>
using namespace std;

int n;
int arr[51][51];
int dp[51][51];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void Input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		for (int j = 0; j < n; j++)
		{
			arr[i][j] = input[j] - '0';
		}
	}
}

void Solve()
{
	vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

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

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

			int count = dp[y][x] + (arr[ny][nx] == 0 ? 1 : 0);

			if (count < dp[ny][nx])
			{
				dp[ny][nx] = count;
				if (arr[ny][nx] == 0)
					dq.push_back({ ny, nx });
				else
					dq.push_front({ ny, nx });
			}
		}
	}

	cout << dp[n - 1][n - 1];
}

int main()
{
	Input();

	Solve();
}
