#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10][10];
int arr2[10][10];
int visited[10][10];
int answer;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> virus;
vector<pair<int, int>> candidates;

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 0)
			{
				candidates.push_back({ i, j });
			}
			else if (arr[i][j] == 2)
			{
				virus.push_back({ i,j });
			}
		}
	}
}

void Func(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] == 1 || arr2[ny][nx] == 1)
		{
			continue;
		}

		visited[ny][nx] = 1;
		arr2[ny][nx] = 2;
		Func(ny, nx);
	}
}

void Func2()
{
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr2[i][j] == 0)
			{
				count++;
			}
		}
	}

	answer = max(answer, count);
}

void Solve()
{
	int size = candidates.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			for (int k = j + 1; k < size; k++)
			{
				memcpy(arr2, arr, sizeof(arr));
				memset(visited, 0, sizeof(visited));

				arr2[candidates[i].first][candidates[i].second] = 1;
				arr2[candidates[j].first][candidates[j].second] = 1;
				arr2[candidates[k].first][candidates[k].second] = 1;

				for (const auto& pos : virus)
				{
					Func(pos.first, pos.second);
				}

				Func2();
			}
		}
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