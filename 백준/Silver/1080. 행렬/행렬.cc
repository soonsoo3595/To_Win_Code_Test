#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[51][51];
int arr2[51][51];

void Input()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < M; j++)
        {
            arr[i][j] = input[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < M; j++)
        {
            arr2[i][j] = input[j] - '0';
        }
    }
}

bool Check()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] != arr2[i][j])
                return false;
        }
    }

    return true;
}

void Change(int y, int x)
{
    for (int i = y; i < y + 3; i++)
    {
        for (int j = x; j < x + 3; j++)
        {
            arr[i][j] = 1 - arr[i][j];
        }
    }
}

void Solve()
{
    int cnt = 0;

    for (int i = 0; i <= N - 3; i++)
    {
        for (int j = 0; j <= M - 3; j++)
        {
            if (arr[i][j] != arr2[i][j])
            {
                Change(i, j);
                cnt++;
            }
        }
    }

    if (Check())
        cout << cnt;
    else
        cout << -1;
}

int main() 
{
    Input();

    Solve();

    return 0;
}
