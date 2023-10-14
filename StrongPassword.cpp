#include <bits/stdc++.h>

using namespace std;

string numbers = "0123456789";
string lower_case = "abcdefghijklmnopqrstuvwxyz";
string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string special_characters = "!@#$%^&*()-+";
int ret = 0;

int minimumNumber(int n, string password) {
    bool digit = false;
    bool lowercase = false;
    bool uppercase = false;
    bool special = false;

    for (int i = 0; i < n; i++)
    {
        if (find(numbers.begin(), numbers.end(), password[i]) != numbers.end() && !digit)
        {
            digit = true;
            continue;
        }

        if (find(lower_case.begin(), lower_case.end(), password[i]) != lower_case.end() && !lowercase)
        {
            lowercase = true;
            continue;
        }

        if (find(upper_case.begin(), upper_case.end(), password[i]) != upper_case.end() && !uppercase)
        {
            uppercase = true;
            continue;
        }

        if (find(special_characters.begin(), special_characters.end(), password[i]) != special_characters.end() && !special)
        {
            special = true;
            continue;
        }
    }

    if (!digit)
        ret++;
    if (!lowercase)
        ret++;
    if (!uppercase)
        ret++;
    if (!special)
        ret++;

    if (ret < 6 - n)
        ret = 6 - n;

    return ret;
}

int main()
{
    int n;
    string password;
    
    cin >> n;
    getline(cin, password); // 버퍼 비우기

    getline(cin, password);

    cout << minimumNumber(n, password);

    return 0;
}

