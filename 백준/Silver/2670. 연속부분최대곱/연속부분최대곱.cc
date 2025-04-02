#include <bits/stdc++.h>
using namespace std;

int N;
double arr[10001];
double dp[10001];
double answer;

void Input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }
       
}

void Solve()
{
    for (int i = 1; i < N; i++)
    {
        dp[i] = max(arr[i], dp[i - 1] * arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        answer = max(answer, dp[i]);
    }

    cout.precision(3);
    cout << fixed << answer;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Solve();

    return 0;
}