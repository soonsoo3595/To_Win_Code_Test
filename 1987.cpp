#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;
int R, C;
char arr[MAX + 4][MAX + 4];
int visited[MAX + 4][MAX + 4];

int dy[] = {-1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

vector<char> path;
int answer;

bool Search(char c)
{
    for (char alpha : path)
    {
        if (alpha == c)
            return true;
    }

    return false;
}

void DFS(int y, int x)
{
    if (visited[y][x]) return;
    
    path.push_back(arr[y][x]);
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        if (visited[ny][nx] || Search(arr[ny][nx])) continue;

        DFS(ny, nx);
    }

    answer = max(answer, (int)path.size());
    path.pop_back();
    visited[y][x] = 0;
}

int main()
{
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < C; j++)
        {
            arr[i][j] = input[j];
        }
    }
    
    DFS(0, 0);

    cout << answer;

    return 0;
}

