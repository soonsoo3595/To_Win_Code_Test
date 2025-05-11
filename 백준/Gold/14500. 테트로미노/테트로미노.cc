#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[504][504];
bool visited[504][504];
int answer = 0;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void Input() 
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
}

void DFS(int y, int x, int depth, int sum) 
{
	if (depth == 4) 
	{
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++) 
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (visited[ny][nx]) continue;

		visited[ny][nx] = true;
		DFS(ny, nx, depth + 1, sum + arr[ny][nx]);
		visited[ny][nx] = false;
	}
}

void CheckExtraShape(int y, int x) 
{
	// ㅗ, ㅏ, ㅜ, ㅓ 모양
	int center = arr[y][x];
	for (int i = 0; i < 4; i++) {
		int tempSum = center;
		bool valid = true;

		for (int j = 0; j < 3; j++) {
			int dir = (i + j) % 4;
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
				valid = false;
				break;
			}
			tempSum += arr[ny][nx];
		}

		if (valid) {
			answer = max(answer, tempSum);
		}
	}
}

void Solve() 
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			visited[i][j] = true;
			DFS(i, j, 1, arr[i][j]);
			visited[i][j] = false;
			CheckExtraShape(i, j);
		}
	}
	cout << answer << "\n";
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}