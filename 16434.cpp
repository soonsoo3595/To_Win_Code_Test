#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll N, atk;

struct Room
{
    int t, a, h;
};

vector<Room> v;

bool Check(ll maxHP)
{
    ll curHP = maxHP;
    ll curAtk = atk;

    for (int i = 0; i < N; i++)
    {
        int t = v[i].t;
        int a = v[i].a;
        int h = v[i].h;

        if (t == 1)
        {
            ll n = ceil((double)h / curAtk);

            if (curHP - a * (n - 1) <= 0) return false;
            curHP -= a * (n - 1);
        }
        else if (t == 2)
        {
            curHP = min(maxHP, curHP + h);
            curAtk += a;
        }
    }

    return true;
}
int main()
{
    cin >> N >> atk;

    for (int i = 0; i < N; i++)
    {
        Room room;
        cin >> room.t >> room.a >> room.h;
        
        v.push_back(room);
    }

    ll low = 0; ll high = LLONG_MAX;
    ll ret = LLONG_MAX;

    while (low <= high)
    {
        ll mid = (low + high) / 2;

        if (Check(mid))
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

