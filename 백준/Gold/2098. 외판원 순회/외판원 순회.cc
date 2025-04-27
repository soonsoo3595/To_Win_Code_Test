#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N;
int arr[16][16];
int dp[16][1 << 16];

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
}

int DFS(int current, int visited)
{
	if (visited == (1 << N) - 1)
	{
		if (arr[current][0] == 0)
		{
			return INF;
		}

		return arr[current][0];
	}

	if (dp[current][visited] != -1)
		return dp[current][visited];

	dp[current][visited] = INF;

	for (int next = 0; next < N; next++)
	{
		if (arr[current][next] == 0) continue;
		if (visited & (1 << next)) continue;

		int nextCost = arr[current][next] + DFS(next, visited | (1 << next));
		dp[current][visited] = min(dp[current][visited], nextCost);
	}

	return dp[current][visited];
}

void Solve()
{
	memset(dp, -1, sizeof(dp));

	cout << DFS(0, 1 << 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}
