#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, int> m;
vector<string> v;

int main()
{
    cin >> N >> M;

    while (N--)
    {
        string input;
        cin >> input;
        m[input]++;
    }

    while (M--)
    {
        string input;
        cin >> input;
        m[input]++;
    }

    for (auto it : m)
    {
        if (it.second == 2)
            v.push_back(it.first);
    }

    cout << v.size() << '\n';

    for (string s : v)
    {
        cout << s << '\n';
    }

    return 0;
}

