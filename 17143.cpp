#include <bits/stdc++.h>

using namespace std;

int arr[104][104];

int R, C, M;
int fisher = 0;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

int answer;

struct Shark
{
    int r;
    int c;
    int s;
    int d;
    int z;

    void Create(int r, int c, int s, int d, int z)
    {
        this->r = r;
        this->c = c;
        this->s = s;
        this->d = d;
        this->z = z;

        CheckIn();
    }

    void Move()
    {
        CheckOut();

        for (int i = 0; i < s; i++)
        {
            int nr = r + dy[d - 1];
            int nc = c + dx[d - 1];

            if (nr < 1 || nc < 1 || nr > R || nc > C)
            {
                if (d == 1)
                    d = 2;
                else if (d == 2)
                    d = 1;
                else if (d == 3)
                    d = 4;
                else if (d == 4)
                    d = 3;

                i--;
                continue;
            }

            r = nr; c = nc;
        }

        CheckIn();
    }

    void CheckIn()
    {
        arr[r][c]++;
    }

    void CheckOut()
    {
        arr[r][c]--;
    }
};
vector<Shark> v;

void Print()
{
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin >> R >> C >> M;

    for (int i = 0; i < M; i++)
    {
        Shark shark;
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark.Create(r, c, s, d, z);
        v.push_back(shark);
    }

    
    while (fisher < 1)
    {
        fisher++;

        for (int i = 0; i < v.size(); i++)
        {
            v[i].Move();
        }

    }
    
    return 0;
}

