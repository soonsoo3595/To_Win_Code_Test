#include <bits/stdc++.h>

using namespace std;

int N;
int arr[128][128];

int white, blue;

bool check(int y, int x, int depth)
{
    int num = arr[y][x];

    for (int i = y; i < y + depth; i++)
    {
        for (int j = x; j < x + depth; j++)
        {
            if (num != arr[i][j])
                return false;
        }
    }

    return true;
}

void Func(int y, int x, int depth)
{
    if (depth == 0) return;

    if (check(y, x, depth))
    {
        if (arr[y][x] == 1)
            blue++;
        else
            white++;
    }
    else
    {
        Func(y, x, depth / 2);
        Func(y, x + depth / 2, depth / 2);
        Func(y + depth / 2, x, depth / 2);
        Func(y + depth / 2, x + depth / 2, depth / 2);
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    Func(0, 0, N);

    cout << white << '\n' << blue;

    return 0;
}

