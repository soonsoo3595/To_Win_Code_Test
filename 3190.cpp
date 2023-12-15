#include <bits/stdc++.h>

using namespace std;

int N, K, L;
int arr[104][104];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct Snake
{
    vector<pair<int, int>> pos;
    int dv = 1;

    pair<int, int> head;
    pair<int, int> tail;

    bool Move()
    {
        bool apple = false;

        head = pos[0];
        tail = pos[(int)pos.size() - 1];

        // 머리의 이동
        pair<int, int> prev = pos[0];
        pos[0].first = head.first + dy[dv];
        pos[0].second = head.second + dx[dv];

        // 예외 처리 -> 벽 밖으로 나가거나 몸통에 부딪히거나
        if (pos[0].first < 0 || pos[0].second < 0 || pos[0].first >= N || pos[0].second >= N) return false;
        if (arr[pos[0].first][pos[0].second] == 2) return false;

        // 사과를 먹었으면
        if (arr[pos[0].first][pos[0].second] == 1)
            apple = true;

        // 머리를 제외한 몸통의 이동
        for (int i = 1; i < pos.size(); i++)
        {
            pair<int, int> temp = pos[i];
            pos[i] = prev;
            prev = temp;
        }

        if (apple)
        {
            Eat();
        }
        else
        {
            arr[tail.first][tail.second] = 0;
        }

        Mark();

        return true;
    }

    void Rotate(char C)
    {
        if (C == 'L')
        {
            if (dv == 0)
                dv = 3;
            else
                dv--;
        }
        else if (C == 'D')
        {
            if (dv == 3)
                dv = 0;
            else
                dv++;
        }
    }

    void Eat()
    {
        pos.push_back(tail);
    }

    void Mark()
    {
        for (int i = 0; i < pos.size(); i++)
        {
            arr[pos[i].first][pos[i].second] = 2;
        }
    }
};

int main()
{
    cin >> N;
    cin >> K;

    Snake s;
    s.pos.push_back({ 0, 0 });

    arr[0][0] = 2;

    for (int  i = 0; i < K; i++)
    {
        int y, x;
        cin >> y >> x;
        arr[y - 1][x - 1] = 1;
    }

    cin >> L;
    vector<pair<int, char>> v;

    for (int i = 0; i < L; i++)
    {
        int X; char C;
        cin >> X >> C;
        v.push_back({ X,C });
    }

    int rotate_cnt = 0;
    int answer = 0;

    for (int t = 1; ; t++)
    {
        if (!s.Move())
        {
            answer = t;
            break;
        }

        if (rotate_cnt < L && t == v[rotate_cnt].first)
        {
            s.Rotate(v[rotate_cnt].second);
            rotate_cnt++;
        }
    }

    cout << answer;

    return 0;
}

