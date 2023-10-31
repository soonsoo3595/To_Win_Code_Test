#include <bits/stdc++.h>

using namespace std;
map<string, int> m;

bool solution(vector<string> phone_book) {
    bool answer = true;

    for (int i = 0; i < phone_book.size(); i++)
    {
        m[phone_book[i]] = i + 1;
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            string s = phone_book[i].substr(0, j + 1);
            if (m[s] == i + 1) continue;
            else if (m[s] != 0)
            {
                answer = false;
                return answer;
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> v;

    v.push_back("11");
    v.push_back("12");
    v.push_back("111");

    cout << solution(v) << "\n";



    return 0;
}