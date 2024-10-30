#include <bits/stdc++.h>

using namespace std;

int T;

bool IsPalindrome(string s, int left, int right)
{
    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s;

        int left = 0;
        int right = s.length() - 1;
        int result = 0;

        while (left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                if (IsPalindrome(s, left + 1, right) || IsPalindrome(s, left, right - 1))
                {
                    result = 1;
                    break;
                }
                else
                {
                    result = 2;
                    break;
                }
            }
        }
        cout << result << '\n';
    }

    return 0;
}
