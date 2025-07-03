#include <bits/stdc++.h>

using namespace std;

// nCr
long long dp[31][31];

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= 30; i++)
    {
        dp[i][1] = i;
        dp[i][i] = 1;
    }

    for (int i = 3; i <= 30; i++)
    {
        for (int j = 2; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        cout << dp[M][N] << '\n';
    }

    return 0;
}

