#include <bits/stdc++.h>

using namespace std;

int a, d, k;

void Input() 
{
	cin >> a >> d >> k;
}

void Solve()
{
	int diff = k - a;

	if ((diff % d == 0) && ((diff / d) >= 0))
	{
		cout << (diff / d + 1);
	}
	else
	{
		cout << "X";
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