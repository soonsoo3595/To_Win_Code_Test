#include <bits/stdc++.h>

using namespace std;

char arr[51][51];
int visited[51][51];

int N, M, answer;
int Diff;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int BFS(int y, int x)
{
    int time = 0;
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = 1;

    while (!q.empty())
    {
        pair<int, int> here = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (arr[ny][nx] == 'W' || visited[ny][nx]) continue;

            q.push({ ny, nx });
            visited[ny][nx] = visited[here.first][here.second] + 1;
            time = max(time, visited[ny][nx]);
        }
    }

    return time - 1;
}

void Print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < M; j++)
        {
            arr[i][j] = input[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 'L')
            {
                int time = BFS(i, j);

                memset(visited, 0, sizeof(visited));
                answer = max(answer, time);
            }
        }
    }

    cout << answer;

    return 0;
}

