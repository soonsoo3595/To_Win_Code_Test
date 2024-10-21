#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    cin >> N;
    
    int count = 0;

    for (int i = 666; ; i++)
    {
        string s = to_string(i);

        for (int j = 2; j < s.size(); j++)
        {
            if (s[j - 2] == '6' && s[j - 1] == '6' && s[j] == '6')
            {
                count++;
                break;
            }
        }

        if (count == N)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}

