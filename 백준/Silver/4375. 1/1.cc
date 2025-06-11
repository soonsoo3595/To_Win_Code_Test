#include <bits/stdc++.h>

using namespace std;

void Input() 
{
	
}

void Solve()
{
	int n;

	while (cin >> n)
	{
		int current = 1;
		int count = 1;

		while ((current % n) != 0)
		{
			current = (current * 10 + 1) % n;
			count++;
		}

		cout << count << '\n';
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
