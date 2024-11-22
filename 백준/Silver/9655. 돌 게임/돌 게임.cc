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
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;

    for (int i = 4; i <= N; i++)
    {
        if (dp[i - 1] == 1)
            dp[i] = 2;
        else
            dp[i] = 1;
    }

    if (dp[N] == 1) cout << "SK";
    else cout << "CY";
        
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}

// 1 : SK
// 2 : CY
// 3 : SK
// 4 : CY
// 5 : SK
// 6 : 