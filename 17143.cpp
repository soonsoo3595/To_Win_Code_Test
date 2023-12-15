#include <bits/stdc++.h>

using namespace std;

int arr[104][104];  // ������, �� ĭ�� �� �� ���� �ִ� ���� �ǹ��Ѵ�.

int R, C, M;
int fisher = 0; // ���ÿ��� ���� �� ��ġ

// ���⺤�� : ��, ��, ��, ��, d�� ������� ǥ��
int dy[] = { -1, 1, 0, 0 }; 
int dx[] = { 0, 0, 1, -1 };

int answer; // ���� ����

// ��� ����ü
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

    // ����� ������
    void Move()
    {
        CheckOut();

        // �ð����⵵ ������ �ӷ� s�� �ٿ��� �Ѵ�. 
        int ss;
        if (d == 1 || d == 2)
            ss = s % (R * 2 - 2);
        else if (d == 3 || d == 4)
            ss = s % (C * 2 - 2);

        for (int i = 0; i < ss; i++)
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

    // �� ���� ��ġ�� ������ arr �迭�� ǥ��
    void CheckIn()
    {
        arr[r][c]++;
    }

    // �� ���� ��ġ���� ��������� ǥ��
    void CheckOut()
    {
        arr[r][c]--;
    }

    // ���ÿ��� �� ����� ��
    void Catch()
    {
        answer += z;
        CheckOut();
    }
};
vector<Shark> v;

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

    
    while (fisher <= C)
    {
        fisher++;
        bool catched = false;

        // ���ÿ��� �̵� �� ���� ���� �ִ� �� ��´�
        for (int i = 1; i <= R; i++)
        {
            if (arr[i][fisher] && !catched)
            {
                for (int j = 0; j < v.size(); j++)
                {
                    if (v[j].r == i && v[j].c == fisher)
                    {
                        v[j].Catch();
                        catched = true;
                        v.erase(v.begin() + j);
                        break;
                    }
                }
            }
        }

        // ������ �̵��Ѵ�.
        for (int i = 0; i < v.size(); i++)
        {
            v[i].Move();
        }

        // �̵� �� ���� ĭ�� �ִ� ��� ó��
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                // �� ���� �� �� ���� �̻��̸�
                if (arr[i][j] >= 2)
                {
                    // vv ���ʹ� ���� ���� �ִ� ������ ����, ���Դ� ��� ���� �ٸ��Ƿ� �ε����� Ȱ�� ����
                    vector<int> vv;

                    for (int k = 0; k < v.size(); k++)
                    {
                        if (v[k].r == i && v[k].c == j)
                        {
                            vv.push_back(v[k].z);
                        }
                    }

                    sort(vv.begin(), vv.end(), greater<int>());

                    for (int k = 1; k < vv.size(); k++)
                    {
                        for (int w = 0; w < v.size(); w++)
                        {
                            if (v[w].z == vv[k])
                            {
                                v[w].CheckOut();
                                v.erase(v.begin() + w);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << answer;

    return 0;
}

