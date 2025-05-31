#include <bits/stdc++.h>

using namespace std;

int a, d, k;

void Input() 
{
	cin >> a >> d >> k;
}

void Solve()
{
	int idx = 1;

	while (true)
	{
		int num = a + (idx - 1) * d;

		if (num == k)
		{
			cout << idx;
			break;
		}

		if (d > 0)
		{
			if (num > k)
			{
				cout << "X";
				break;
			}
		}
		else
		{
			if (num < k)
			{
				cout << "X";
				break;
			}
		}

		idx++;
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