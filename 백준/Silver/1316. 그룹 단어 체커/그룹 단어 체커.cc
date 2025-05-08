#include <bits/stdc++.h>
using namespace std;

int N;
int answer;

void Input()
{
	cin >> N;
}

void Solve()
{
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		bool flag = true;
		vector<char> v;
		for (int j = 0; j < s.size(); j++)
		{
			if (find(v.begin(), v.end(), s[j]) == v.end())
			{
				v.push_back(s[j]);
			}
			else if(s[j] != s[j - 1])
			{
				flag = false;
			}
		}

		if (flag)
			answer++;
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}
