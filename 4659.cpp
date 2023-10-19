#include <bits/stdc++.h>

using namespace std;


int func4(char c)
{
    // 모음이면 1, 자음이면 -1 리턴
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    else
        return -1;
}

bool func1(string pw)
{
    for (char c : pw)
    {
        if (func4(c) == 1)
            return true;
    }

    return false;
}

bool func2(string pw)
{
    bool flag = true;

    for (int i = 0; i < (int)pw.size() - 1; i++)
    {
        if (pw[i] == pw[i + 1])
        {
            if (pw[i] == 'e' || pw[i] == 'o')
            {
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
    }

    return flag;
}

bool func3(string pw)
{
    for (int i = 0; i < (int)pw.size() - 2; i++)
    {
        if (func4(pw[i]) == func4(pw[i + 1]) && func4(pw[i + 1]) == func4(pw[i + 2]))
        {
            return false;
        }
    }

    return true;
}



int main()
{
    while (true)
    {
        string pw;
        cin >> pw;

        if (pw == "end")
            break;
        
        if (func1(pw))
        {
            if (func2(pw))
            {
                if (func3(pw))
                {
                    cout << "<" << pw << "> is acceptable.\n";
                    continue;
                }
            }
        }
        
        cout << "<" << pw << "> is not acceptable.\n";

    }

    return 0;
}

