#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll X, Y, Z;

int main()
{
    cin >> X >> Y;

    Z = (Y * 100) / X;

    ll low = 0;
    ll high = X;

    ll ret = -1;

    while (low <= high)
    {
        ll mid = (low + high) / 2;

        if (((Y + mid) * 100 / (X + mid)) > Z)
        {
            high = mid - 1;
            ret = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ret << '\n';

    return 0;
}

