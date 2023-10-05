#include <bits/stdc++.h>

using namespace std;

int N, result;
string s;
stack<char> st1, st2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--)
	{
		cin >> s;
		
		for (char c : s)
		{
			st1.push(c);
		}

		while (!st1.empty())
		{
			if (!st2.empty())
			{
				if (st2.top() == st1.top())
				{
					st1.pop();
					st2.pop();
				}
				else
				{
					st2.push(st1.top());
					st1.pop();
				}
			}
			else
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
		
		if (st2.empty())
			result++;
		else
		{
			while (!st2.empty())
				st2.pop();
		}
	}

	cout << result;
}