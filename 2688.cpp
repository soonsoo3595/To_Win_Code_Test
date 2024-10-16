#include <bits/stdc++.h>

using namespace std;

int T, n;
long long dp[65][10];

int main()
{
    cin >> T;

    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= 64; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            long long value = 0;

            for(int k = 0; k <= j; k++)
            {
                value += dp[i - 1][k];
            }

            cout << "dp[" << i << "][" << j << "] = " << value << '\n';
            dp[i][j] = value;
        }
    }


    while (T--)
    {
        cin >> n;

        long long sum = 0;

        for (int i = 0; i < 10; i++)
        {
            sum += dp[n][i];
        }

        cout << sum << '\n';
    }

    return 0;
}

