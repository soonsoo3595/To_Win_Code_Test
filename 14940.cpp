#include <bits/stdc++.h>

using namespace std;

int arr[1004][1004];
int visited[1004][1004];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int cy, cx;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 2)
            {
                cy = i; cx = j;
            }
        }
    }

    memset(visited, -1, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({ cy, cx });
    visited[cy][cx] = 0;

    while (!q.empty())
    {
        int y, x;
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] > 0 || arr[ny][nx] == 0)   continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0 || (i == cy) && (j == cx))
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << visited[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}

