#include <bits/stdc++.h>

using namespace std;

int M;
int S;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> M;

    while (M--)
    {
        string input;
        int x;

        cin >> input;

        if (input == "add")
        {
            cin >> x;
            if(S & (1 << x - 1)) continue;
            S |= (1 << x - 1);
        }
        else if (input == "remove")
        {
            cin >> x;
            if (!(S & (1 << x - 1))) continue;

            S &= ~(1 << x - 1);
        }
        else if (input == "check")
        {
            cin >> x;
            if(S & (1 << x - 1)) cout << 1 << '\n';
			else cout << 0 << '\n';
        }
        else if (input == "toggle")
        {
            cin >> x;
            S ^= (1 << x - 1);
        }
        else if (input == "all")
        {
            S = (1 << 20) - 1;
        }
        else if (input == "empty")
        {
            S = 0;
        }
    }

    return 0;
}

