#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> coin;
int dp[10004];

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int input; cin >> input;
        coin.push_back(input);
    }

    fill(dp, dp + 10004, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        if (coin[i] > 10000) continue;

        dp[coin[i]] = 1;

        for (int j = coin[i]; j <= 10000; j++)
        {
            if (dp[j - coin[i]] == INT_MAX) continue;

            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    if (dp[k] == INT_MAX)
        cout << -1;
    else
        cout << dp[k];
    

    return 0;
}
 