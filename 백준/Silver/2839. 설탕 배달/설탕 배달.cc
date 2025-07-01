#include <bits/stdc++.h>

using namespace std;

int N;
int dp[5004];

int main()
{
    cin >> N;

    memset(dp, -1, sizeof(dp));

    dp[3] = 1;
    dp[5] = 1;

    for (int i = 6; i <= N; i++)
    {
        if (dp[i - 3] == -1 && dp[i - 5] != -1)
        {
            dp[i] = dp[i - 5] + 1;
        }
        else if (dp[i - 3] != -1 && dp[i - 5] == -1)
        {
            dp[i] = dp[i - 3] + 1;
        }
        else if (dp[i - 3] != -1 && dp[i - 5] != -1)
        {
            dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
        }
    }

    cout << dp[N];

    return 0;
}

