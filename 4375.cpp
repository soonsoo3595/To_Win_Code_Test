#include <bits/stdc++.h>

using namespace std;

int N;
int answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	while (!cin.eof())
	{
		cin >> N;
		string s = "111";

		while (true)
		{
			cout << s << '\n';

			if (s.size() > 10)
			{
				if (s.size() == 11)
				{
					long long num = 11111111111;
					if (num % N == 0)
					{
						answer = 11;
						break;
					}
				}
				else if (s.size() == 12)
				{
					long long num = 111111111111;
					if (num % N == 0)
					{
						answer = 12;
						break;
					}
				}
			}
			else
			{
				if (atoi(s.c_str()) % N == 0)
				{
					answer = s.size();
					break;
				}
			}

			s += "1";
		}

		cout << answer << '\n';
	}
	
	/*
	long long a = 1111111111111;
	int b = 9999;

	while (true)
	{
		if (a % b == 0)
		{
			cout << a << ' ' << b << '\n';
		}
		b--;
		
	}
	*/
}