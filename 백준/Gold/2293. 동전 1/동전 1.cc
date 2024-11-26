#include <bits/stdc++.h>
using namespace std;

int n, k;
int coin[104];
int dp[10004];    // dp[i] = i를 만들 수 있는 경우의 수

void Input()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> coin[i];
}

void Solve()
{
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (coin[i] > 10000) continue;

        for (int j = coin[i]; j <= k; j++)
        {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[k];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}
