#include <bits/stdc++.h>
using namespace std;

int N, K;
int T[11][11];
int answer = INT_MAX;

void Input()
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> T[i][j];
        }
    }
}

void DFS(int here, int time, int visit)
{
    if (visit == (1 << N) - 1)
    {
        answer = min(answer, time);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (visit & (1 << i)) continue;

        DFS(i, time + T[here][i], visit | (1 << i));
    }
}

void Solve()
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (T[i][j] > T[i][k] + T[k][j])
                {
                    T[i][j] = T[i][k] + T[k][j];
                }
            }
        }
    }

    DFS(K, 0, 1 << K);

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
