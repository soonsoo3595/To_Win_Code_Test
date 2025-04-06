#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1004];
int dp[1004];

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

void Solve()
{
	fill(dp, dp + 1004, INT_MAX);
	dp[0] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (j + arr[j] >= i && dp[j] != INT_MAX)
			{
				dp[i] = min(dp[i], dp[j] + 1);
			}
		}
	}

	if (dp[N - 1] == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << dp[N - 1];
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