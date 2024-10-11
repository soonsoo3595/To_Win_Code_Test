#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1004];
int dp[1004];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(j + arr[j] >= i && dp[j] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    if (dp[N - 1] == INT_MAX)
        cout << -1;
    else
        cout << dp[N - 1];

    return 0;
}

