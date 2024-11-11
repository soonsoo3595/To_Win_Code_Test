#include <bits/stdc++.h>
using namespace std;

int T, N;
char cards[1004];

void Solve();

void Input()
{
    cin >> T;
    
    while (T--)
    {
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> cards[i];
        }

        Solve();
    }
}

void Solve()
{
    deque<char> dq;
    dq.push_back(cards[0]);

    for (int i = 1; i < N; i++)
    {
        if (cards[i] > dq.front())
        {
            dq.push_back(cards[i]);
        }
        else
        {
            dq.push_front(cards[i]);
        }
    }

    for (char c : dq)
    {
        cout << c;
    }

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    // Solve();

    return 0;
}
