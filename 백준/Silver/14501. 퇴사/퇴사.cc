#include <bits/stdc++.h>
using namespace std;

int N;
int T[20], P[20];
int dp[20];

void Input()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}
}

void Solve()
{
	for (int i = N; i > 0; i--)
	{
		if (T[i] + i > N + 1)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + 1], dp[i + T[i]] + P[i]);
		}
	}

	cout << dp[1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}
