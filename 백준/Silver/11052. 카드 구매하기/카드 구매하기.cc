#include <bits/stdc++.h>
using namespace std;

int N;
int P[1004];
int dp[1004];

void Input()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> P[i];
}

void Solve()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            dp[j] = max(dp[j], dp[j - i] + P[i]);
        }
    }

    cout << dp[N];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}
