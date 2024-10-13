#include <bits/stdc++.h>

using namespace std;

long long N;
long long arr[104][104];
long long dp[104][104];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dp[i][j] == 0) continue;
            if (arr[i][j] == 0) continue;

            if (i + arr[i][j] < N)
            {
                dp[i + arr[i][j]][j] = dp[i][j] + dp[i + arr[i][j]][j];
            }

            if (j + arr[i][j] < N)
            {
                dp[i][j + arr[i][j]] = dp[i][j] + dp[i][j + arr[i][j]];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << dp[N - 1][N - 1];

    return 0;
}

