#include <bits/stdc++.h>
using namespace std;

int N;
int arr[130][130];

int blue, white;

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
	int color = arr[y][x];

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (color != arr[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

void Func(int y, int x, int size)
{
	if (Check(y, x, size))
	{
		if (arr[y][x] == 0)
			white++;
		else
			blue++;

		return;
	}
	else
	{
		int nextSize = size / 2;
		Func(y, x, nextSize);
		Func(y + nextSize, x, nextSize);
		Func(y, x + nextSize, nextSize);
		Func(y + nextSize, x + nextSize, nextSize);
	}
}

void Solve()
{
	Func(0, 0, N);

	cout << white << '\n' << blue;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}
