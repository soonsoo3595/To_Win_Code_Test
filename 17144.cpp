#include <bits/stdc++.h>

using namespace std;

int R, C, T;
int arr[54][54];
int arr2[54][54];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

vector<int> v;

void Spread()
{
    memcpy(arr2, arr, sizeof(arr));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] < 5) continue;

            int count = 0;

            for (int k = 0; k < 4; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
                if (arr[ny][nx] == -1) continue;

                arr2[ny][nx] += floor(arr[i][j] / 5);
                count++;
            }

            arr2[i][j] -= (floor(arr[i][j] / 5) * count);
        }
    }

    memcpy(arr, arr2, sizeof(arr));
}

void UpClean()
{
    int prev = 0;
    for (int i = 1; i < C; i++)
    {
        int temp = arr[v[0]][i];
        arr[v[0]][i] = prev;
        prev = temp;
    }

    for (int i = v[0] - 1; i >= 0; i--)
    {
        int temp = arr[i][C - 1];
        arr[i][C - 1] = prev;
        prev = temp;
    }

    for (int i = C - 2; i >= 0; i--)
    {
        int temp = arr[0][i];
        arr[0][i] = prev;
        prev = temp;
    }

    for (int i = 1; i < v[0]; i++)
    {
        int temp = arr[i][0];
        arr[i][0] = prev;
        prev = temp;
    }
}

void DownClean()
{
    int prev = 0;
    for (int i = 1; i < C; i++)
    {
        int temp = arr[v[1]][i];
        arr[v[1]][i] = prev;
        prev = temp;
    }

    for (int i = v[1] + 1; i < R; i++)
    {
        int temp = arr[i][C - 1];
        arr[i][C - 1] = prev;
        prev = temp;
    }

    for (int i = C - 2; i >= 0; i--)
    {
        int temp = arr[R - 1][i];
        arr[R - 1][i] = prev;
        prev = temp;
    }

    for (int i = R - 2; i > v[1]; i--)
    {
        int temp = arr[i][0];
        arr[i][0] = prev;
        prev = temp;
    }
}

int main()
{
    cin >> R >> C >> T;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == -1)
                v.push_back(i);
        }
    }

    while (T--)
    {
        Spread();

        UpClean();
        DownClean();
    }

    int sum = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == -1 || arr[i][j] == 0) continue;
            sum += arr[i][j];
        }
    }

    cout << sum;

    return 0;
}

