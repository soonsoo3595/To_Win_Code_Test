#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[101][10];
const int Mod = 1000000000;

int main()
{
    cin >> N;

    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= 100; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j - 1 >= 0)
                dp[i][j] += (dp[i - 1][j - 1] % Mod);

            if (j + 1 < 10)
                dp[i][j] += (dp[i - 1][j + 1] % Mod);
        }
    }


    long long sum = 0;

    for (int i = 0; i < 10; i++)
    {
        sum += (dp[N][i] % Mod);
    }

    cout << sum % Mod;

    return 0;
}

