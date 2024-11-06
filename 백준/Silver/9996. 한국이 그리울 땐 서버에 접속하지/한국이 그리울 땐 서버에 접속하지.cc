#include <bits/stdc++.h>
using namespace std;

int N;
string pattern;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> pattern;

    string first = pattern.substr(0, pattern.find('*'));
    string last = pattern.substr(pattern.find('*') + 1);

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        if (str.size() < first.size() + last.size())
        {
            cout << "NE\n";
            continue;
        }

        string compareFirst = str.substr(0, first.size());
        string compareLast = str.substr(str.size() - last.size());

        if (compareFirst == first && compareLast == last)
            cout << "DA\n";
        else
            cout << "NE\n";
    }

    return 0;
}