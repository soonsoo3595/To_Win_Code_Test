#include <bits/stdc++.h>

using namespace std;

int M, N;
int arr[54][54];
int visited[54][54];

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

int answer1, answer2, answer3;
int room;

void DFS(int y, int x)
{
    room++;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
        if (arr[y][x] & (1 << i) || visited[ny][nx]) continue;

        DFS(ny, nx);
    }

}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j]) continue;
            room = 0;
            DFS(i, j); answer1++;
            answer2 = max(answer2, room);
        }
    }
    

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                memset(visited, 0, sizeof(visited));

                if (arr[i][j] & (1 << k))
                {
                    arr[i][j] &= ~(1 << k);
                    room = 0;
                    DFS(i, j);
                    answer3 = max(answer3, room);
                    arr[i][j] |= (1 << k);
                }
            }
        }
    }

    cout << answer1 << '\n' << answer2 << '\n' << answer3;

    return 0;
}

