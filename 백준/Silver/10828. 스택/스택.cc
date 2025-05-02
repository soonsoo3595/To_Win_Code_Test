#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> S;

void Input()
{
	cin >> N;
}

void Solve()
{
	while (N--)
	{
		string str;
		int X = 0;

		cin >> str;

		if (str == "push")
		{
			cin >> X;
			S.push(X);
		}
		else if (str == "pop")
		{
			if (S.empty())
				cout << -1 << '\n';
			else
			{
				cout << S.top() << '\n';
				S.pop();
			}
		}
		else if (str == "size")
			cout << S.size() << '\n';
		else if (str == "empty")
			cout << S.empty() << '\n';
		else if (str == "top")
		{
			if (S.empty())
				cout << -1 << '\n';
			else
				cout << S.top() << '\n';
		}
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
