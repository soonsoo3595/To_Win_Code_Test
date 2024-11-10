#include <bits/stdc++.h>
using namespace std;

int N;
int arr[24][24];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int visited[24][24];

struct Pos
{
    int y, x;
};

int shark = 2;
int eat_count = 0;
Pos sharkPos;

void Input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            
            if (arr[i][j] == 9)
            {
                sharkPos = { i, j };
                arr[i][j] = 0;
            }
        }
    }
}

void BFS()
{
    memset(visited, -1, sizeof(visited));

    queue<Pos> q;
    q.push(sharkPos);
    visited[sharkPos.y][sharkPos.x] = 0;

    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] != -1) continue;
            if (shark < arr[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }
}


bool CanEat(Pos pos)
{
    if (shark > arr[pos.y][pos.x])
        return true;
    else
        return false;
}

bool Compare(Pos& p1, Pos& p2)
{
    if (p1.y == p2.y)
    {
        return p1.x < p2.x;
    }

    return p1.y < p2.y;
}

Pos FindFish()
{
    Pos ret = { -1, -1 };

    int distance = 1000000;

    vector<Pos> sub;

    BFS();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 물고기이며 상어보다 크기가 작은 물고기를 찾는다 -> 먹을 수 있는 물고기를 찾는다와 같은 의미
            if (arr[i][j] >= 1 && arr[i][j] < shark && visited[i][j] != -1)
            {
                if (visited[i][j] < distance)
                {
                    distance = visited[i][j];
                    sub.clear();
                    sub.push_back({ i, j });
                }
                else if (visited[i][j] == distance)
                {
                    sub.push_back({ i, j });
                }
            }
        }
    }

    if (!sub.empty())
    {
        sort(sub.begin(), sub.end(), Compare);
        ret = sub[0];
    }

    return ret;
}

void Solve()
{
    int answer = 0;

    while (true)
    {
        Pos pos = FindFish();

        if (pos.y == -1 && pos.x == -1) break;

        answer += (visited[pos.y][pos.x]);
        sharkPos = pos;
        arr[pos.y][pos.x] = 0;
        eat_count++;

        if (shark == eat_count)
        {
            shark++;
            eat_count = 0;
        }
    }

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
