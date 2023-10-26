#include <bits/stdc++.h>

using namespace std;

int R, C;
char arr[1004][1004];

int visited1[1004][1004];
int visited2[1004][1004];

vector<pair<int, int>> v1;
vector<pair<int, int>> v2;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void Print()
{
    cout << "=======================\n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << visited1[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=======================\n";

    cout << "=======================\n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << visited2[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=======================\n";

}

void BFS1(queue<pair<int, int>>& q)
{
    int y, x;

    while (q.size())
    {
        tie(y, x) = q.front(); q.pop();
        if (!visited1[y][x]) visited1[y][x] = 1;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (visited1[ny][nx] || arr[ny][nx] == '#') continue;

            q.push({ ny, nx });
            visited1[ny][nx] = visited1[y][x] + 1;
        }
        
    }
}

void BFS2(queue<pair<int, int>>& q)
{
    int y, x;

    while (q.size())
    {
        tie(y, x) = q.front(); q.pop();
        if (!visited2[y][x]) visited2[y][x] = 1;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (visited2[ny][nx] || arr[ny][nx] == '#') continue;

            q.push({ ny, nx });
            visited2[ny][nx] = visited2[y][x] + 1;
        }

    }
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

            if (input[j] == 'J')
                v1.push_back({ i, j });
            else if (input[j] == 'F')
                v2.push_back({ i, j });
        }
    }

    queue<pair<int, int>> q;

    for (auto p : v2)
    {
        q.push(p);
    }

    BFS1(q);

    for (auto p : v1)
    {
        q.push(p);
    }

    BFS2(q);
    // Print();

    int answer = INT_MAX;

    // 위쪽 가장자리
    for (int i = 0; i < C; i++)
    {
        if (arr[0][i] == '#') continue;
        if (visited2[0][i] == 0) continue;
        if (visited1[0][i] > visited2[0][i])
        {
            answer = min(answer, visited2[0][i]);
        }
    }

    for (int i = 0; i < C; i++)
    {
        if (arr[R - 1][i] == '#') continue;
        if (visited2[R - 1][i] == 0) continue;

        if (visited1[R - 1][i] > visited2[R - 1][i])
        {
            answer = min(answer, visited2[R - 1][i]);
        }
    }

    for (int i = 0; i < R; i++)
    {
        if (arr[i][0] == '#') continue;
        if (visited2[i][0] == 0) continue;

        if (visited1[i][0] > visited2[i][0])
        {
            answer = min(answer, visited2[i][0]);
        }
    }

    for (int i = 0; i < R; i++)
    {
        if (arr[i][C - 1] == '#') continue;
        if (visited2[i][C - 1] == 0) continue;

        if (visited1[i][C - 1] > visited2[i][C - 1])
        {
            answer = min(answer, visited2[i][C - 1]);
        }
    }

    if (answer == INT_MAX)
        cout << "IMPOSSIBLE\n";
    else
        cout << answer;

    return 0;
}

