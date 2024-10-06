#include <bits/stdc++.h>

using namespace std;

int N;
char arr[104][104];
bool visited[104][104];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void Go(int y, int x)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
        if (arr[ny][nx] == arr[y][x])
        {
            Go(ny, nx);
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < N; j++)
        {
            arr[i][j] = input[j];
        }
    }

    int answer1 = 0;
    int answer2 = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j]) continue;
            Go(i, j);
            answer1++;
        }
    }

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 'G')
                arr[i][j] = 'R';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j]) continue;
            Go(i, j);
            answer2++;
        }
    }

    cout << answer1 << ' ' << answer2;

    return 0;
}

