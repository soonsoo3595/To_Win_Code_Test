#include <bits/stdc++.h>
using namespace std;

int l;

int ty, tx;
int answer;

int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int visited[304][304];

void BFS(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({ y, x });

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        if (cy == ty && cx == tx)
        {
            return;
        }

        for (int i = 0; i < 8; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || nx < 0 || ny >= l || nx >= l || visited[ny][nx]) continue;

            q.push({ ny, nx });
            visited[ny][nx] = visited[cy][cx] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> l;

        int cy, cx;
        cin >> cy >> cx;
        cin >> ty >> tx;

        memset(visited, 0, sizeof(visited));
        BFS(cy, cx);

        cout << visited[ty][tx] << '\n';
    }

    return 0;
}