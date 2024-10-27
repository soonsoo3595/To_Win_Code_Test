#include <bits/stdc++.h>

using namespace std;

int N;

int arr[100004][3];
int dp[3];
int dp2[3];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    dp[0] = dp2[0] = arr[0][0];
    dp[1] = dp2[1] = arr[0][1];
    dp[2] = dp2[2] = arr[0][2];

    for (int i = 1; i < N; i++)
    {
        int left = dp[0];
        int mid = dp[1];
        int right = dp[2];

        dp[0] = max(left, mid) + arr[i][0];
        dp[1] = max(max(left, mid), right) + arr[i][1];
        dp[2] = max(mid, right) + arr[i][2];
    }
    
    for (int i = 1; i < N; i++)
    {
        int left = dp2[0];
        int mid = dp2[1];
        int right = dp2[2];

        dp2[0] = min(left, mid) + arr[i][0];
        dp2[1] = min(min(left, mid), right) + arr[i][1];
        dp2[2] = min(mid, right) + arr[i][2];
    }

    cout << max(dp[0], max(dp[1], dp[2])) << ' ' << min(dp2[0], min(dp2[1], dp2[2]));

    return 0;
}
