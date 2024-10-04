#include <bits/stdc++.h>

using namespace std;

int N, M;
char arr[604][604];
int visited[604][604];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int cx, cy;
int answer;

void Go(int y, int x)
{
    visited[y][x] = 1;

    if (arr[y][x] == 'P')
        answer++;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || arr[ny][nx] == 'X')
            continue;

        Go(ny, nx);
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

            if (arr[i][j] == 'I')
            {
                cy = i;
                cx = j;
            }
        }
    }

    Go(cy, cx);
    
    if (answer == 0)
        cout << "TT";
    else
        cout << answer;


    return 0;
}

