#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[504][504];
int dp[504][504];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void Input() 
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int DFS(int y, int x)
{
    if (y == N - 1 && x == M - 1)
    {
        return 1;
    }

    int& ret = dp[y][x];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (arr[y][x] <= arr[ny][nx]) continue;

        ret += DFS(ny, nx);
    }

    return ret;
}

void Solve()
{
    memset(dp, -1, sizeof(dp));
    cout << DFS(0, 0);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Solve();

    return 0;
}