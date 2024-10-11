#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1004];
long long dp[1004];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

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

    return 0;
}

