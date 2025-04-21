#include <bits/stdc++.h>

using namespace std;

int N, K;
int W[104], V[104]; // i번째 물건의 무게, 가치
int dp[100004];

int main()
{
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        int w, v;
        cin >> w >> v;
        W[i] = w; V[i] = v;
    }
    
    for (int i = 1; i <= N; i++)
    {
        for (int w = K; w >= W[i]; w--)
        {
            dp[w] = max(dp[w], dp[w - W[i]] + V[i]);
        }
    }

    cout << dp[K];

    return 0;
}

