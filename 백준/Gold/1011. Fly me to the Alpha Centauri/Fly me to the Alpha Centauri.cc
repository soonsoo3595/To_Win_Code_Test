#include <bits/stdc++.h>

using namespace std;

int T;

void Input()
{
	cin >> T;
}

void Solve()
{
	while (T--)
	{
		long long x, y;
		cin >> x >> y;

		long long dist = y - x;
		long long move = 0;
		long long speed = 0;

		while (speed * speed <= dist)
		{
			speed++;
		}

		speed -= 1;
		move = speed * 2 - 1;

		long long remain = dist - speed * speed;
		long long plus = ceil((double)remain / speed);
		cout << move + plus << '\n';
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
