#include <bits/stdc++.h>
using namespace std;

int N;
int dice[10004][6];
int opposite[6] = { 5, 3, 4, 1, 2, 0 };

int answer;

void Input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> dice[i][j];
        }
    }
}

int GetMaxSide(int idx, int top)
{
    int ret = 0;

    for (int i = 0; i < 6; i++)
    {
        if (i == top || i == opposite[top]) continue;
        
        ret = max(ret, dice[idx][i]);
    }

    return ret;
}

void Func(int current, int top, int sum)
{
    if (current == N - 1)
    {
        answer = max(answer, sum + GetMaxSide(current, top));
        return;
    }

    int max_side = GetMaxSide(current, top);
    int next_bottom = 0;

    for (int i = 0; i < 6; i++)
    {
        if (dice[current][top] == dice[current + 1][i])
        {
            next_bottom = i;
            break;
        }
    }

    Func(current + 1, opposite[next_bottom], sum + max_side);
}

void Solve()
{
    for (int i = 0; i < 6; i++)
    {
        Func(0, i, 0);
    }
    
    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}
