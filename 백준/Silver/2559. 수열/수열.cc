#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[100004];
int psum[100004];

void Input()
{
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }
}

void Solve()
{
    int answer = INT_MIN;

    for (int i = K; i <= N; i++)
    {
        answer = max(answer, psum[i] - psum[i - K]);
    }

    cout << answer;
}

int main() 
{
    Input();

    Solve();

    return 0;
}

// 3 -2 -4 -9 0 3 7 13 8 -3
// 3 1 -3 -12 -12 -9 -2 11 19 16
