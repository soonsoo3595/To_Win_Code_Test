#include <bits/stdc++.h>

using namespace std;

int answer;

int alternate(string s) {

    set<char> set;
    vector<char> v;

    for (char c : s)
    {
        set.insert(c);
    }

    for (char c : set)
    {
        v.push_back(c);
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            string temp = "";
            bool flag = true;

            for (char c : s)
            {
                if (c == v[i] || c == v[j])
                {
                    temp += c;
                }
            }

            for (int k = 0; k < temp.size() - 1; k++)
            {
                if (temp[k] == temp[k + 1])
                {
                    flag = false;
                    break;
                }
            }

            if (flag && temp.size() > 0)
            {
                answer = max(answer, (int)temp.size());
            }
        }
    }

    return answer;
}

int main()
{
    string s;
    getline(cin, s);

    int result = alternate(s);

    cout << result;

    return 0;
}

