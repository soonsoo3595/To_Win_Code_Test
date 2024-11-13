#include <bits/stdc++.h>
using namespace std;

int N;

void Input()
{
    cin >> N;
}

void Solve()
{
    int second = 10;

    int idx = 1;
    while (N >= pow(2, idx++))
    {
        second++;
    }

    cout << second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}
