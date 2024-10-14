#include <bits/stdc++.h>

using namespace std;

int N;
int arr[504][504];
long long dp[504][504];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            }
            else if (j == i)
            {
                dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
            }
        }
    }

    long long answer = 0;

    for (int i = 0; i <= N; i++)
    {
        answer = max(answer, dp[N - 1][i]);
    }

    cout << answer;

    return 0;
}

