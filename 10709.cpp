#include <bits/stdc++.h>

using namespace std;

int H, W;
char arr[104][104];
int answer[104][104];

int go(int y, int x)
{
    // 바로 구름이 있는 경우
    if (arr[y][x] == 'c')
        return 0;

    int diff = 0;
    bool flag = false;

    for (int i = 0; i <= x; i++)
    {
        if (arr[y][i] == 'c')
        {
            diff = x - i;
            flag = true;
        }
    }

    if (flag)
        return diff;
    else
        return -1;
}

int main()
{
    cin >> H >> W;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << go(i, j) << ' ';
        }

        cout << '\n';
    }

    return 0;
}

