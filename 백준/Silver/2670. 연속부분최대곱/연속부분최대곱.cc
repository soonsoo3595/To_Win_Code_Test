#include <bits/stdc++.h>

using namespace std;

int N;
double dp[10004];

int main()
{
    cin >> N;

    vector<double> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    dp[0] = v[0];

    for (int i = 1; i < N; i++)
    {
        dp[i] = max(v[i] * dp[i - 1], v[i]);
    }

    double answer = 0;

    for (int i = 0; i < N; i++)
    {
        if (answer < dp[i])
        {
            answer = dp[i];
        }
    }

    cout.precision(3);
    cout << fixed << answer;
    
    return 0;
}

