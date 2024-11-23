#include <bits/stdc++.h>
using namespace std;

int N;
int house[16][16];
int dp[16][16];

void Input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> house[i][j];
}

// (y, x)가 비어있고 갈 수 있는 지 확인
bool Check(int y, int x)
{
    if (y < 0 || x < 0 || y >= N || x >= N || house[y][x]) return false;

    return true;
}

void Solve()
{
    pair<int, int> pos = { 0, 1 };  // 파이프의 위치
    queue<pair<pair<int, int>, int>> q; // (파이프 위치), (파이프 상태)

    q.push({ pos, 0 });

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int state = q.front().second;
        q.pop();

        dp[y][x]++;

        if (state == 0)         // 가로
        {
            if (Check(y, x + 1))
            {
                q.push({ {y, x + 1}, 0 });
            }

            if (Check(y, x + 1) && Check(y + 1, x + 1) && Check(y + 1, x))
            {
                q.push({ {y + 1, x + 1}, 2 });
            }
        }
        else if (state == 1)    // 세로
        {
            if (Check(y + 1, x))
            {
                q.push({ {y + 1, x}, 1 });
            }

            if (Check(y, x + 1) && Check(y + 1, x + 1) && Check(y + 1, x))
            {
                q.push({ {y + 1, x + 1}, 2 });
            }
        }
        else if (state == 2)    // 대각선
        {
            if (Check(y, x + 1))
            {
                q.push({ {y, x + 1}, 0 });
            }

            if (Check(y + 1, x))
            {
                q.push({ {y + 1, x}, 1 });
            }

            if (Check(y, x + 1) && Check(y + 1, x + 1) && Check(y + 1, x))
            {
                q.push({ {y + 1, x + 1}, 2 });
            }
        }
    }

    cout << dp[N - 1][N - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}