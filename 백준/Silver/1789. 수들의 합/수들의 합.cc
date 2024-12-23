#include <bits/stdc++.h>
using namespace std;

long long S;
long long N;

void Input() 
{
    cin >> S;
}

void Solve()
{
    for (long long i = 1; i <= S; i++)
    {
        long long sum = i * (i + 1) / 2;

        if (sum > S)
        {
            break;
        }

        if (S - sum > i)
        {
            N = max(N, i);
        }
    }

    cout << N + 1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Solve();

    return 0;
}