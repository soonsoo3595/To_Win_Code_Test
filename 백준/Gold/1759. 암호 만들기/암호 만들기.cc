#include <bits/stdc++.h>

using namespace std;

int L, C;
vector<char> alpha;
vector<char> password;

void Func(int start, int length)
{
    if (length == L)
    {
        int count1 = 0;     // 모음 개수
        int count2 = 0;     // 자음 개수

        string s;
        for (char c : password)
        {
            s += c;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }

        if (count1 >= 1 && count2 >= 2)
        {
            cout << s << '\n';
        }

        return;
    }

    for (int i = start; i < C; i++)
    {
        password.push_back(alpha[i]);
        Func(i + 1, length + 1);
        password.pop_back();
    }
}

int main()
{
    cin >> L >> C;

    for (int i = 0; i < C; i++)
    {
        char c;
        cin >> c;
        alpha.push_back(c);
    }

    sort(alpha.begin(), alpha.end());

    Func(0, 0);

    return 0;
}
