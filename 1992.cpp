#include <bits/stdc++.h>

using namespace std;

int N;
char arr[66][66];

string ret;

#pragma region Fail
/*
#include <bits/stdc++.h>

using namespace std;

int N;
int arr[66][66];

string ret;

struct Pos
{
    int y;
    int x;

    Pos(int y, int x)
    {
        this->y = y;
        this->x = x;
    }
};

void QuadTree(Pos start, Pos end)
{
    if (start.y == end.y && start.x == end.x)
    {
        ret += (arr[start.y][start.x] + '0');
        return;
    }
    // cout << "Start : (" << start.y << "," << start.x << ")\n";
    // cout << "End : (" << end.y << "," << end.x << ")\n";

    int compare = arr[start.y][start.x];
    bool flag = true;

    for (int y = start.y; y <= end.y; y++)
    {
        for (int x = start.x; x <= end.x; x++)
        {
            if (arr[y][x] != compare)
            {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }

    if (flag)
    {
        // cout << compare << "Ãß°¡\n";
        ret += (compare + '0');
        return;
    }
    else
    {
        // cout << "°ıÈ£¿­°í\n";

        ret += '(';
        // cout << "¿ŞÂÊ À§ Å½»ö ½ÃÀÛ\n";
        QuadTree(Pos(start.y, start.x), Pos((start.y + end.y) / 2, (start.x + end.x) / 2));
        // cout << "¿ŞÂÊ À§ Å½»ö ³¡\n";

        // cout << "¿À¸¥ÂÊ À§ Å½»ö ½ÃÀÛ\n";
        QuadTree(Pos(start.y, (start.x + end.x) / 2 + 1), Pos((start.y + end.y) / 2, end.x));
        // cout << "¿À¸¥ÂÊ À§ Å½»ö ³¡\n";

        // cout << "¿ŞÂÊ ¾Æ·¡ Å½»ö ½ÃÀÛ\n";
        QuadTree(Pos(end.y / 2 + 1, start.x), Pos(end.y, (start.x + end.x) / 2));
        // cout << "¿ŞÂÊ ¾Æ·¡ Å½»ö ³¡\n";

        // cout << "¿À¸¥ÂÊ ¾Æ·¡ Å½»ö ½ÃÀÛ\n";
        QuadTree(Pos((start.y + end.y) / 2 + 1, (start.x + end.x) / 2 + 1), Pos(end.y, end.x));
        // cout << "¿À¸¥ÂÊ ¾Æ·¡ Å½»ö ³¡\n";

        // cout << "°ıÈ£´İ°í\n";
        ret += ')';
    }

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
            arr[i][j] = input[j] - '0';
        }
    }


    QuadTree(Pos(0, 0), Pos(N - 1, N - 1));
    cout << ret;

    return 0;
}

*/
#pragma endregion

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

