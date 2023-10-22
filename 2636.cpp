#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[104][104];
int visited[104][104];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int cheese; // ÃÑ Ä¡Áî °³¼ö
int cnt;

void Func(int y, int x)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visited[ny][nx]) continue;

        if (arr[ny][nx] == 1)
        {
            visited[ny][nx] = 1;
            arr[ny][nx] = 0;
            cnt++;
            continue;
        }
        Func(ny, nx);
    }
}

bool Func2()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            if (arr[i][j] == 1)
                return false;
        }
    }
    
    return true;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                cheese++;
        }
    }

    int time = 0;

    while (true)
    {
        cnt = 0;
        time++;
        for (int i = 0; i < N; i++)
        {
            if (arr[i][0] == 0 && !visited[i][0])
                Func(i, 0);
            if (arr[i][M - 1] == 0 && !visited[i][M - 1])
                Func(i, M - 1);
        }

        for (int j = 0; j < M; j++)
        {
            if (arr[0][j] == 0 && !visited[0][j])
                Func(0, j);

            if (arr[N - 1][j] == 0 && !visited[N - 1][j])
                Func(N - 1, j);
        }

        if (Func2())
            break;

        memset(visited, 0, sizeof(visited));

        cheese -= cnt;
    }

    cout << time << '\n' << cheese;

    return 0;
}
