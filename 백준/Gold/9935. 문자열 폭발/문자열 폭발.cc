#include <bits/stdc++.h>
using namespace std;

string str;
string bomb;
stack<char> stk;

void Input()
{
    cin >> str >> bomb;
}

void Solve()
{
    for (int i = 0; i < str.length(); i++)
    {
        stk.push(str[i]);
        
        if (str[i] == bomb.back())
        {
            if (stk.size() >= bomb.size())
            {
                string compare = "";

                for (int j = 0; j < bomb.size(); j++)
                {
                    compare += stk.top();
                    stk.pop();
                }

                reverse(compare.begin(), compare.end());

                if (compare != bomb)
                {
                    for (int j = 0; j < compare.size(); j++)
                    {
                        stk.push(compare[j]);
                    }
                }
            }
        }
    }

    if (stk.empty())
        cout << "FRULA";
    else
    {
        string answer = "";

        while (!stk.empty())
        {
            answer += stk.top();
            stk.pop();
        }

        reverse(answer.begin(), answer.end());
        cout << answer;
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
