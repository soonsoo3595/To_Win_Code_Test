#include <bits/stdc++.h>
using namespace std;

int X;

void Input()
{
	cin >> X;
}

void Solve()
{
	int line = 1;

	while (true)
	{
		if (X - line <= 0)
		{
			break;
		}

		X -= line;
		line++;
	}

	if (line % 2)
	{
		cout << (line - X + 1) << '/' << X << '\n';
	}
	else
	{
		cout << X << '/' << (line - X + 1) << '\n';
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
