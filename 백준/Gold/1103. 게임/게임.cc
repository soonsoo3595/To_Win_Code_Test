#include <bits/stdc++.h>
using namespace std;

int N, M;
char arr[54][54];
int dp[54][54];
int visited[54][54];

int answer;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void Input()
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
}

int Func(int y, int x)
{
    if (y < 0 || x < 0 || y >= N || x >= M || arr[y][x] == 'H') return 0;

    if (visited[y][x])
    {
        cout << "-1";
        exit(0);
    }

    if (dp[y][x]) return dp[y][x];
    visited[y][x] = 1;

    int move = arr[y][x] - '0';

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i] * move;
        int nx = x + dx[i] * move;

        dp[y][x] = max(dp[y][x], Func(ny, nx) + 1);
    }

    visited[y][x] = 0;

    return dp[y][x];
}

void Solve()
{
    cout << Func(0, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}