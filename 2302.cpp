#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[41];
long long dp[41];
long long dp2[41];

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int fix;
        cin >> fix;
        arr[fix] = 1;
    }

    dp2[0] = 1;
    dp2[1] = 1;

    for (int i = 2; i <= 40; i++)
    {
        dp2[i] = dp2[i - 1] + dp2[i - 2];
    }

    dp[0] = 1;

    int num = 1;
    int continue_count = 1;

    for (int i = 1; i <= N; i++)
    {
        if (arr[i] == 1)
        {
            dp[i] = dp[i - 1];

            num = dp[i];
            continue_count = 1;
            continue;
        }
        
        dp[i] = num * dp2[continue_count++];
    }

    cout << dp[N];

    return 0;
}

