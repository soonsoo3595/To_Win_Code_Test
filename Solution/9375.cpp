#include <bits/stdc++.h>

using namespace std;

int T, n;
string name, type;
map<string, int> m;
set<string> s;

int main()
{
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		
		int result = 1;

		for (int i = 0; i < n; i++)
		{
			cin >> name >> type;
			s.insert(type);
			m[type]++;
		}

		for (string str : s)
		{
			result *= m[str];
		}

		cout << result + n << '\n';

		m.clear();
		s.clear();
	}
}