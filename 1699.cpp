#include <bits/stdc++.h>
using namespace std;

int N;
int dp[100004];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		dp[i] = i;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N];
}