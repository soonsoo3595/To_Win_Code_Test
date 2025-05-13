#include <bits/stdc++.h>
using namespace std;

vector<int> cards;

void Input()
{
    for (int i = 0; i < 4; ++i) {
        int x;
        cin >> x;
        cards.push_back(x);
    }
}

int getMinClockNum(const vector<int>& v) {
    int res = 10000;
    vector<int> t = v;
    for (int i = 0; i < 4; ++i) {
        int num = t[0]*1000 + t[1]*100 + t[2]*10 + t[3];
        res = min(res, num);
        rotate(t.begin(), t.begin()+1, t.end());
    }
    return res;
}

void Solve()
{
    int myNum = getMinClockNum(cards);

    set<int> s;
    for (int i = 1111; i <= 9999; ++i) {
        int n = i;
        vector<int> v(4);
        for (int j = 3; j >= 0; --j) {
            v[j] = n % 10;
            n /= 10;
        }
        
        if (find(v.begin(), v.end(), 0) != v.end()) continue;
        s.insert(getMinClockNum(v));
    }

    int cnt = 1;
    for (int x : s) {
        if (x == myNum) {
            cout << cnt << '\n';
            return;
        }
        cnt++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Solve();

    return 0;
}