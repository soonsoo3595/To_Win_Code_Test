#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
int N;
char arr[MAX + 4][MAX + 4];

int row_cnt, col_cnt;

int row(int y)
{
    int ret = 0;
    int num = 0;

    for (int i = 0; i < N; i++)
    {
        if (arr[y][i] == '.')
        {
            num++;
        }
        else
        {
            if (num >= 2)
                ret++;

            num = 0;
        }
    }

    if (num >= 2)
        ret++;

    return ret;
}

int col(int x)
{
    int ret = 0;
    int num = 0;

    for (int i = 0; i < N; i++)
    {
        if (arr[i][x] == '.')
        {
            num++;
        }
        else
        {
            if (num >= 2)
                ret++;

            num = 0;
        }
    }

    if (num >= 2)
        ret++;

    return ret;
}

int main()
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < N; j++)
        {
            arr[i][j] = input[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        row_cnt += row(i);
    }

    for (int i = 0; i < N; i++)
    {
        col_cnt += col(i);
    }

    cout << row_cnt << ' ' << col_cnt;

    return 0;
}

