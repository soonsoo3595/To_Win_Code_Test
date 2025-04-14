#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10][10];
vector<pair<int, int>> v;
int answer = INT_MAX;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<vector<vector<int>>> directions = {
	{},
	{{0}, {1}, {2}, {3}},
	{{0, 2}, {1, 3}},
	{{0, 1}, {1, 2}, {2, 3}, {3, 0}},
	{{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}}, 
	{{0, 1, 2, 3}}                             
};

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] >= 1 && arr[i][j] <= 5)
			{
				v.push_back({ i, j });
			}
		}
	}
}

void Watch(int y, int x, int dir, int temp[10][10])
{
	while (true)
	{
		y += dy[dir];
		x += dx[dir];

		if (y < 0 || x < 0 || y >= N || x >= M || temp[y][x] == 6)
			break;

		if (temp[y][x] == 0)
			temp[y][x] = 7;
	}
}

void Simulate(const vector<int>& dir_choice)
{
	int temp[10][10];
	memcpy(temp, arr, sizeof(temp));

	for (int i = 0; i < v.size(); i++)
	{
		int y = v[i].first;
		int x = v[i].second;
		int cctv = arr[y][x];
		int d_index = dir_choice[i];

		for (int dir : directions[cctv][d_index])
		{
			Watch(y, x, dir, temp);
		}
	}

	// 사각지대 개수 세기
	int blind = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (temp[i][j] == 0)
				blind++;

	answer = min(answer, blind);
}

void DFS(int index, vector<int>& cctv_dir)
{
	if (index == v.size())
	{
		Simulate(cctv_dir);
		return;
	}

	int y = v[index].first;
	int x = v[index].second;
	int cctv = arr[y][x];

	for (int i = 0; i < directions[cctv].size(); i++)
	{
		cctv_dir[index] = i;
		DFS(index + 1, cctv_dir);
	}
}

void Solve()
{
	vector<int> cctv_dir(v.size());
	DFS(0, cctv_dir);
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