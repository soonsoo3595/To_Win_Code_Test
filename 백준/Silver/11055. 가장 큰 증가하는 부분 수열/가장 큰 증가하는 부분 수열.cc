#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1004];
int dp[1004];

void Input()
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}


void Solve()
{
    for (int i = 0; i < N; i++)
    {
        dp[i] = arr[i];

        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
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