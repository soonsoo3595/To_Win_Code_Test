#include <bits/stdc++.h>

using namespace std;

int N;
int L[21];
int J[21];
int dp[101];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> L[i];
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> J[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int hp = 100; hp > L[i]; hp--)
        {
            dp[hp] = max(dp[hp], dp[hp - L[i]] + J[i]);
        }
    }

    cout << dp[100];

    return 0;
}

