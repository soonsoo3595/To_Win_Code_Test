#include <bits/stdc++.h>

using namespace std;

const int MAX = 300;
int N, M;
char arr[MAX + 4][MAX + 4];
int visited[MAX + 4][MAX + 4];
int x_1, y_1, x_2, y_2;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main()
{
    cin >> N >> M;
    cin >> y_1 >> x_1 >> y_2 >> x_2;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = input[j];
        }
    }

    queue<pair<int, int>> q;

    bool flag = true;
    int jump = 0;

    while (flag)
    {
        q.push({ y_1 - 1, x_1 - 1 });
        visited[y_1 - 1][x_1 - 1] = 1;
        jump++;

        while (q.size())
        {
            int y, x;
            tie(y, x) = q.front(); q.pop();

            if (arr[y][x] == '1')
            {
                arr[y][x] = 0;
                continue;
            }

            if (visited[y_2 - 1][x_2 - 1])
            {
                flag = false;
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (visited[ny][nx]) continue;
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ ny, nx });
            }
        }

        if (!flag) break;
        memset(visited, 0, sizeof(visited));
    }

    cout << jump;

    return 0;
}

