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
            if (visited1[ny][nx] <= visited2[y][x] + 1) continue; // 불이 번진 곳은 지나갈 수 없음(불이 번지는 시간보다 늦게 도착한 경우

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

    if (v2.size())
    {
        for (auto p : v2)
        {
            q.push(p);
        }
    }

    BFS1(q);

    for (auto p : v1)
    {
        q.push(p);
    }

    BFS2(q);
    Print();

    int answer = INT_MAX;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if(i != 0 && i != R - 1 && j != 0 && j != C - 1)
				continue;

            if (arr[i][j] == '#') continue;

            answer = min(answer, visited2[i][j]);
        }
    }

    if (answer == INT_MAX)
        cout << "IMPOSSIBLE\n";
    else
        cout << answer;

    return 0;
}

