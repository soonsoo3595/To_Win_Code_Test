#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> land;
vector<pair<int, int>> treasure;

char arr[51][51];
int visited[51][51];

int N, M, answer;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int BFS(int y, int x)
{
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = 1;

    while (q.size())
    {
        pair<int, int> here = q.front(); q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (arr[ny][nx] == 'W' || visited[ny][nx]) continue;

            q.push({ ny, nx });
            visited[ny][nx] = visited[here.first][here.second] + 1;
        }
    }

    return visited[treasure[1].first][treasure[1].second] - visited[treasure[0].first][treasure[0].second];
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
            if (input[j] == 'L')
                land.push_back({ i, j });
        }
    }

    for (int i = 0; i < land.size(); i++)
    {
        treasure.push_back(land[i]);

        for (int j = i + 1; j < land.size(); j++)
        {
            treasure.push_back(land[j]);
            answer = max(BFS(treasure[0].first, treasure[0].second), answer);
            treasure.pop_back();
        }

        treasure.pop_back();
    }

    cout << answer;

    return 0;
}

