#include <bits/stdc++.h>

using namespace std;

string S;
map<string, int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> S;

    int len = S.size();
    for (int i = 1; i <= len; i++)
    {
        for (int j = 0; j <= len - i; j++)
        {
            string s = S.substr(j, i);
            m[s] = 1;
        }
    }

    cout << m.size();

    return 0;
}

