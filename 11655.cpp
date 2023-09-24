#include <bits/stdc++.h>

using namespace std;

string s;

char ROT13(char c)
{
	// ¾ËÆÄºªÀÎÁö
	if (isalpha(c))
	{
		char temp = c + 13;

		if (isupper(c))
		{
			if (temp >= 'A' && temp <= 'Z')
			{
				return temp;
			}
			else
			{
				temp = 'A' + temp - 'Z' - 1;
				return temp;
			}
		}
		else
		{
			if (temp >= 'a' && temp <= 'z')
			{
				return temp;
			}
			else
			{
				temp = 'a' + temp - 'z' - 1;
				return temp;
			}
		}
	}
	else
	{
		return c;
	}
}

int main()
{
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		cout << ROT13(s[i]);
	}
}