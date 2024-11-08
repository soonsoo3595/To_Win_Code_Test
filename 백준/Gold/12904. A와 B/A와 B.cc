#include <bits/stdc++.h>
using namespace std;

string S, T;
bool flag = false;

void Input()
{
    cin >> S >> T;
}

void Solve()
{
    string compare = T;

    while (compare.size() != S.size())
    {
        if (compare.back() == 'A')
        {
            compare.pop_back();
        }
        else
        {
            compare.pop_back();
            reverse(compare.begin(), compare.end());
        }
    }

    if (compare == S)
        cout << 1;
    else
        cout << 0;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}
