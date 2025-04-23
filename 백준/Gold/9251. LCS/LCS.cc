#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int len1, len2;
int dp[1004][1004];

void Input()
{
	cin >> s1 >> s2;
}

void Solve()
{
	len1 = s1.size();
	len2 = s2.size();

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[len1][len2];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}