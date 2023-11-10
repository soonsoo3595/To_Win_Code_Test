#include <bits/stdc++.h>

using namespace std;

int R, C, K;
char arr[10][10];
int visited[10][10];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int answer;

void Go(int y, int x, int distance)
{
    if (y == 0 && x == C - 1)
    {
        if (distance == K) answer++;

        return;
    }

    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || arr[ny][nx] == 'T') continue;

        Go(ny, nx, distance + 1);
    }

    visited[y][x] = 0;
}


int main()
{
    cin >> R >> C >> K;

    for (int i = 0; i < R; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < C; j++)
        {
            arr[i][j] = input[j];
        }
    }

    Go(R - 1, 0, 1);

    cout << answer;

    return 0;
}

