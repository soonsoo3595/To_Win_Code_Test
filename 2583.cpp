#include <bits/stdc++.h>

using namespace std;

int M, N, K;
int filled[104][104];
int visited[104][104];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int ret, width;
vector<int> widths;

void DFS(int y, int x)
{
    visited[y][x] = 1;
    width++;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
        if (filled[ny][nx] == 1 || visited[ny][nx]) continue;

        DFS(ny, nx);
    }
}

int main()
{
    cin >> M >> N >> K;

    while (K--)
    {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        for (int y = ly; y < ry; y++)
        {
            for (int x = lx; x < rx; x++)
            {
                filled[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            width = 0;

            if (filled[i][j] == 0 && !visited[i][j])
            {
                DFS(i, j);
                ret++;
                widths.push_back(width);
            }
        }
    }

    sort(widths.begin(), widths.end());
    cout << ret << '\n';

    for (int i : widths)
    {
        cout << i << ' ';
    }

    return 0;
}

