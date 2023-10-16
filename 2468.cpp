#include <bits/stdc++.h>

using namespace std;

int N;
int arr[104][104];
int visited[104][104];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int answer = 1;

void go(int y, int x, int height)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny > N || nx > N) continue;
        if (arr[ny][nx] <= height || visited[ny][nx]) continue;
        go(ny, nx, height);
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int k = 1; k <= 100; k++)
    {
        memset(visited, 0, sizeof(visited));
        int count = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[i][j] > k && !visited[i][j])
                {
                    go(i, j, k);
                    count++;
                }
            }
        }

        answer = max(answer, count);
    }

    cout << answer;
    return 0;
}

