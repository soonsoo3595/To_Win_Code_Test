#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> v;

string func1(string str)
{
    string ret = "";

    bool flag = false;

    // "0010" 일때 앞에 두 0만 지워야함
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0' && !flag)
        {
            continue;
        }
        else
        {
            ret += str[i];
            flag = true;
        }
    }

    if (ret == "")
        ret = "0";

    return ret;
}

bool compare(string s1, string s2)
{
    if (s1.size() < s2.size()) {
        return true;  // s2가 더 큰 값
    }
    else if (s1.size() > s2.size()) {
        return false;   // s1이 더 큰 값
    }
    else {
        return s1 < s2; // 길이가 같으면 사전 순으로 비교
    }
}

// 숫자가 엄청 큰 경우를 생각해야 됨
int main()
{
    cin >> N;

    while (N--)
    {
        string word;
        string number = "";

        cin >> word;

        for (int i = 0; i < word.size(); i++)
        {

            if (word[i] >= '0' && word[i] <= '9')
            {
                number += word[i];
            }
            else
            {
                if (!number.empty())
                {
                    v.push_back(func1(number));
                    number = "";
                }
            }

        }

        if (!number.empty())
        {
            v.push_back(func1(number));
        }
        
    }

    sort(v.begin(), v.end(), compare);

    for (string s : v)
    {
        cout << s << '\n';
    }

    return 0;
}

