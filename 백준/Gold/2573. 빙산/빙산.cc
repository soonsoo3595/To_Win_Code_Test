#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[304][304];
int arr2[304][304];
bool visited[304][304];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int Check(int y, int x)
{
    int count = 0;

    if (y > 1)
    {
        if (arr[y - 1][x] == 0)
            count++;
    }

    if (y < N)
    {
        if (arr[y + 1][x] == 0)
            count++;
    }

    if (x > 1)
    {
        if (arr[y][x - 1] == 0)
            count++;
    }

    if (x < M)
    {
        if (arr[y][x + 1] == 0)
            count++;
    }

    return count;
}

void DFS(int y, int x)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 1 || nx < 1 || ny > N || nx > M || visited[ny][nx] || arr2[ny][nx] == 0) continue;

        DFS(ny, nx);
    }
}

void Melt(int y, int x)
{
    int count = Check(y, x);
    arr2[y][x] = max(0, arr2[y][x] - count);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }

    memcpy(arr2, arr, sizeof(arr2));
    int year = 0;

    while (true)
    {
        year++;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (arr[i][j] != 0)
                    Melt(i, j);
            }
        }


        int count = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (arr2[i][j] != 0 && !visited[i][j])
                {
                    DFS(i, j);
                    count++;
                }
            }
        }

        if (count >= 2)
        {
            cout << year;
            break;
        }
        else if (count == 0)
        {
            cout << 0;
            break;
        }

        memset(visited, false, sizeof(visited));
        memcpy(arr, arr2, sizeof(arr));
    }

    return 0;
}
