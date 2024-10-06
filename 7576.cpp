#include <bits/stdc++.h>

using namespace std;

int M, N;
int arr[1001][1001];
bool visited[1001][1001];

int answer;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool Check()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
                return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                q.push({ i, j });
        }
    }

    while (!Check())
    {
        queue<pair<int, int>> checkQueue(q);

        while (!q.empty())
            q.pop();

        while (!checkQueue.empty())
        {
            int y, x;
            tie(y, x) = checkQueue.front();
            checkQueue.pop();

            visited[y][x] = true;

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
                if (arr[ny][nx] == 0)
                {
                    arr[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
        }

        if (q.empty())
        {
            answer = -1;
            break;
        }

        answer++;
    }

    cout << answer;

    return 0;
}

