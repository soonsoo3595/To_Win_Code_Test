#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10004];
int dp[10004];

void Input()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
}

void Solve()
{
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]), dp[i - 1]);
    }

    cout << dp[n];
}

int main()
{
    Input();

    Solve();

    return 0;
}