#include <bits/stdc++.h>

using namespace std;

vector<int> adj[8];
int visited[8];

void DFS(int u)
{
    visited[u] = 1;
    cout << u << ' ';

    for (int v : adj[u])
    {
        if (visited[v] == 0)
        {
            DFS(v);
        }
    }
}
int main()
{
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(5);
    adj[3].push_back(4);
    adj[2].push_back(6);
    adj[6].push_back(7);

    DFS(0);

    return 0;
}

/* ¿¬½À
#include <bits/stdc++.h>

using namespace std;

int arr[101][101];
int visited[101][101];

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int N, M;
int answer;

int cy, cx;
int gy, gx;

void DFS(int y, int x)
{
    cout << y << " : " << x << '\n';

    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny > N || nx > M)
            continue;
        if (visited[ny][nx])
            continue;
        if (arr[ny][nx] == 0)
            continue;

        DFS(ny, nx);
    }
}

void BFS(int y, int x)
{
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));

    while (!q.empty())
    {
        tie(y,x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;
            if (arr[ny][nx] == 0 || visited[ny][nx])
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
}
int main()
{
    cin >> N >> M;

#pragma region Example_DFS
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && arr[i][j])
            {
                answer++;
                DFS(i, j);
            }
        }
    }
#pragma endregion

#pragma region Example_BFS
cin >> cy >> cx;
cin >> gy >> gx;

for (int i = 0; i < N; i++)
{
    for (int j = 0; j < M; j++)
    {
        cin >> arr[i][j];
    }
}

BFS(cy, cx);
cout << visited[gy][gx];
#pragma endregion

return 0;
}


*/
