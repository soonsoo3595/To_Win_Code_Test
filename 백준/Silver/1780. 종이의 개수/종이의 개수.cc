#include <bits/stdc++.h>

using namespace std;

int N;
int arr[3000][3000];
int ans0, ans1, ans2;

void Input() 
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
}

bool Check(int y, int x, int size)
{
	int opt = arr[y][x];

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (opt != arr[i][j])
			{
				return false;
			}
		}
	}

	if (opt == -1)
	{
		ans0++;
	}
	else if (opt == 0)
	{
		ans1++;
	}
	else if (opt == 1)
	{
		ans2++;
	}

	return true;
}

void Func(int y, int x, int size)
{
	if (Check(y, x, size))
	{
		return;
	}

	int nextSize = size / 3;
	Func(y, x, nextSize);
	Func(y, x + nextSize, nextSize);
	Func(y, x + nextSize * 2, nextSize);

	Func(y + nextSize, x, nextSize);
	Func(y + nextSize, x + nextSize, nextSize);
	Func(y + nextSize, x + nextSize * 2, nextSize);

	Func(y + nextSize * 2, x, nextSize);
	Func(y + nextSize * 2, x + nextSize, nextSize);
	Func(y + nextSize * 2, x + nextSize * 2, nextSize);
}

void Solve()
{
	Func(0, 0, N);

	cout << ans0 << '\n' << ans1 << '\n' << ans2;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}
