#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[104][104];
int visited[104][104];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void go(int y, int x)
{
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });
	
	while (!q.empty())
	{
		tie(y, x) = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny > N || nx > M) continue;
			if (arr[ny][nx] == 0 || visited[ny][nx]) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= M; j++)
		{
			arr[i][j] = input[j - 1] - '0';
		}
	}
	
	go(1, 1);

	cout << visited[N][M];

	return 0;

}