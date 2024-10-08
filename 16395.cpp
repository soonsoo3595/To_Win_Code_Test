#include <bits/stdc++.h>

using namespace std;

int n, k;
long long dp[31][31];

int main()
{
    cin >> n >> k;

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cout << dp[n - 1][k - 1];

    return 0;
}

