#include <bits/stdc++.h>

using namespace std;

int N;
int arr[2004];
int dp[2004];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << N - *max_element(dp, dp + N);

    return 0;
}

