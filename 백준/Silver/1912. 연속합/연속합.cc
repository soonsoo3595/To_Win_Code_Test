#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100004];
int dp[100004];

void Input() 
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
}

void Solve()
{
	dp[1] = arr[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	cout << *max_element(dp + 1, dp + n + 1);
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}
