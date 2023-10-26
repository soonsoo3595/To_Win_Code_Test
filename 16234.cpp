#include <bits/stdc++.h>

using namespace std;

int N, L, R;
int A[51][51];
int visited[51][51];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

vector<pair<int, int>> un;

void Print()
{
    cout << "============================\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "============================\n";
}

bool Func2(int num1, int num2)
{
    int diff = abs(num1 - num2);
    
    if (diff >= L && diff <= R)
        return true;
    else
        return false;
}

void Func(int y, int x)
{
    visited[y][x] = 1;
    un.push_back({ y, x });

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (visited[ny][nx]) continue;
        if (!Func2(A[y][x], A[ny][nx])) continue;

        Func(ny, nx);
    }
}

int main()
{
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    int day = 0;

    while (true)
    {
        bool flag = false;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if(!visited[i][j])
                    Func(i, j);

                if (un.size() >= 2)
                {
                    int sum = 0;

                    for (auto c : un)
                    {
                        sum += A[c.first][c.second];
                    }

                    sum = sum / un.size();

                    for (auto c : un)
                    {
                        A[c.first][c.second] = sum;
                    }

                    flag = true;
                }

                un.clear();
            }
        }

        if (!flag)
            break;
        else
            day++;

        memset(visited, 0, sizeof(visited));
    }

    cout << day;

    return 0;
}

