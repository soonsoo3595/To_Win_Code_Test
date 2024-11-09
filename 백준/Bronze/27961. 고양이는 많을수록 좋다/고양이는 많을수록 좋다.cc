#include <bits/stdc++.h>
using namespace std;

long long N;

void Input()
{
    cin >> N;
}

void Solve()
{
    long long cat = 0;
    long long idx = 0;

    while (cat < N)
    {
        cat = pow(2, idx++);
    }

    cout << idx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}
