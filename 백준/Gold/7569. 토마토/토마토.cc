#include <bits/stdc++.h>

using namespace std;

int M, N, H;
int arr[101][101][101];
bool visited[101][101][101];

int answer;

// 위 아래 왼쪽 오른쪽 앞 뒤
int dh[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 0, 0, -1, 1 };
int dx[6] = { 0, 0, -1, 1, 0 ,0 };

struct Pos
{
    int h;
    int y;
    int x;

    Pos(int _h, int _y, int _x)
    {
        h = _h;
        y = _y;
        x = _x;
    }
};

bool Check()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (arr[i][j][k] == 0)
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    queue<Pos> q;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1)
                {
                    q.push(Pos(i, j, k));
                }
            }
        }
    }

    while (!Check())
    {
        queue<Pos> checkQueue(q);

        while (!q.empty())
            q.pop();

        while (!checkQueue.empty())
        {
            Pos pos = checkQueue.front();
            checkQueue.pop();

            int h, y, x;
            h = pos.h; y = pos.y; x = pos.x;
            visited[h][y][x] = true;

            for (int i = 0; i < 6; i++)
            {
                int nh = h + dh[i];
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M || nh < 0 || nh >= H || visited[nh][ny][nx]) continue;
                if (arr[nh][ny][nx] == 0)
                {
                    arr[nh][ny][nx] = 1;
                    q.push(Pos(nh, ny, nx));
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

