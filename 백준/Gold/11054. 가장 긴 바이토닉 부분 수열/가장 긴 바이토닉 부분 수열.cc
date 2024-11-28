#include <bits/stdc++.h>
using namespace std;

int N;
int A[1004];
int dp[1004];

void Input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
}

void Solve()
{
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {   
        for (int j = i + 1; j < N; j++)
        {
            if (A[i] > A[j])
            {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }

    cout << *max_element(dp, dp + N);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}
