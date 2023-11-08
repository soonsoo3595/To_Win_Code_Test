#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> v;

int main()
{
    cin >> N;

    while (N--)
    {
        string input;
        cin >> input;
        v.push_back(input);
    }

    string answer = "";

    for (int i = 0; i < v[0].size(); i++)
    {
        bool flag = false;

        for (int j = 1; j < v.size(); j++)
        {
            if (v[j - 1][i] != v[j][i])
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            answer += "?";
        }
        else
        {
            answer += v[0][i];
        }
    }

    cout << answer;

    return 0;
}

