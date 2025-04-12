#include <bits/stdc++.h>

using namespace std;

int N;
char arr[66][66];

string ret;

void QuadTree(int y, int x, int size)
{
    if (size == 1)
    {
        ret += (arr[y][x]);
        return;
    }

    char compare = arr[y][x];

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (arr[i][j] != compare)
            {
                ret += '(';
                QuadTree(y, x, size / 2);
                QuadTree(y, x + size / 2, size / 2);
                QuadTree(y + size / 2, x, size / 2);
                QuadTree(y + size / 2, x + size / 2, size / 2);
                ret += ')';
                return;
            }
        }
    }

    ret += arr[y][x];

    return;
}

int main()
{
    cin >> N;

    string input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = input[j];
        }
    }


    QuadTree(0, 0, N);
    cout << ret;

    return 0;
}

