#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1004];

void Input()
{
    cin >> N;
}


void Solve()
{
    dp[2] = 1;

    for (int i = 5; i <= N; i++)
    {
        if (dp[i - 1] == 0 && dp[i - 3] == 0 && dp[i - 4] == 0)
            dp[i] = 1;
        else
            dp[i] = 0;
    }

    if (dp[N])
        cout << "CY";
    else
        cout << "SK";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}