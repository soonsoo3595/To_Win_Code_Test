#include <bits/stdc++.h>
using namespace std;

int N, M;
int r, c, d;
int arr[51][51];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int answer;

void Input()
{
    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

}

void Clean(int y, int x)
{
    if (arr[y][x] == 0)
    {
        arr[y][x] = 2;
        answer++;
    }

    bool dirty = false;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (arr[ny][nx] == 0)
        {
            dirty = true;
        }
    }

    if (dirty)
    {
        int ny, nx;

        while(true)
        {
            d = ((d + 4) - 1) % 4;

            ny = y + dy[d];
            nx = x + dx[d];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 1) continue;
            if (arr[ny][nx] == 0)
            {
                break;
            }
        }

        Clean(ny, nx);
    }
    else
    {
        int back = ((d + 4) - 2) % 4;
        int ny = y + dy[back];
        int nx = x + dx[back];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 1) return;
        Clean(ny, nx);
    }

}

void Solve()
{
    Clean(r, c);

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
