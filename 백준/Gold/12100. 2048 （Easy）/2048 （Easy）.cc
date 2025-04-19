#include <bits/stdc++.h>
using namespace std;

int N;
int arr[21][21];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int answer;

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

void Move(int dir)
{
	bool merged[21][21] = { false };

	if (dir == 0)
	{
		// 위로 이동
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 0) continue;
				int y = i;
				while (y > 0 && arr[y - 1][j] == 0)
				{
					swap(arr[y][j], arr[y - 1][j]);
					y--;
				}
				if (y > 0 && arr[y - 1][j] == arr[y][j] && !merged[y - 1][j])
				{
					arr[y - 1][j] *= 2;
					arr[y][j] = 0;
					merged[y - 1][j] = true;
				}
			}
		}
	}
	else if (dir == 1)
	{
		// 오른쪽으로 이동
		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >= 0; j--)
			{
				if (arr[i][j] == 0) continue;
				int x = j;
				while (x < N - 1 && arr[i][x + 1] == 0)
				{
					swap(arr[i][x], arr[i][x + 1]);
					x++;
				}
				if (x < N - 1 && arr[i][x + 1] == arr[i][x] && !merged[i][x + 1])
				{
					arr[i][x + 1] *= 2;
					arr[i][x] = 0;
					merged[i][x + 1] = true;
				}
			}
		}
	}
	else if (dir == 2)
	{
		// 아래로 이동
		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 0) continue;
				int y = i;
				while (y < N - 1 && arr[y + 1][j] == 0)
				{
					swap(arr[y][j], arr[y + 1][j]);
					y++;
				}
				if (y < N - 1 && arr[y + 1][j] == arr[y][j] && !merged[y + 1][j])
				{
					arr[y + 1][j] *= 2;
					arr[y][j] = 0;
					merged[y + 1][j] = true;
				}
			}
		}
	}
	else if (dir == 3)
	{
		// 좌로 이동
		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j < N; j++)
			{
				if (arr[i][j] == 0) continue;
				int x = j;
				while (x > 0 && arr[i][x - 1] == 0)
				{
					swap(arr[i][x], arr[i][x - 1]);
					x--;
				}
				if (x > 0 && arr[i][x - 1] == arr[i][x] && !merged[i][x - 1])
				{
					arr[i][x - 1] *= 2;
					arr[i][x] = 0;
					merged[i][x - 1] = true;
				}
			}
		}
	}
}

void Print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

void DFS(int depth)
{
	if (depth == 5)
	{
		int number = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				number = max(number, arr[i][j]);
			}
		}

		answer = max(answer, number);
		return;
	}

	int temp[21][21];
	memcpy(temp, arr, sizeof(arr));

	for (int dir = 0; dir < 4; dir++)
	{
		Move(dir);
		DFS(depth + 1);
		memcpy(arr, temp, sizeof(arr));
	}
}

void Solve()
{
	DFS(0);
	cout << answer << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}