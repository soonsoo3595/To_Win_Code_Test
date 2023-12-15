#include <bits/stdc++.h>

using namespace std;

int arr[104][104];  // 격자판, 각 칸은 상어가 몇 마리 있는 지를 의미한다.

int R, C, M;
int fisher = 0; // 낚시왕의 현재 열 위치

// 방향벡터 : 상, 하, 우, 좌, d의 순서대로 표현
int dy[] = { -1, 1, 0, 0 }; 
int dx[] = { 0, 0, 1, -1 };

int answer; // 정답 변수

// 상어 구조체
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

    // 상어의 움직임
    void Move()
    {
        CheckOut();

        // 시간복잡도 때문에 속력 s를 줄여야 한다. 
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

    // 상어가 현재 위치에 있음을 arr 배열에 표시
    void CheckIn()
    {
        arr[r][c]++;
    }

    // 상어가 현재 위치에서 사라졌음을 표시
    void CheckOut()
    {
        arr[r][c]--;
    }

    // 낚시왕이 상어를 잡았을 때
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

        // 낚시왕이 이동 후 같은 열에 있는 상어를 잡는다
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

        // 상어들이 이동한다.
        for (int i = 0; i < v.size(); i++)
        {
            v[i].Move();
        }

        // 이동 후 같은 칸에 있는 상어 처리
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                // 한 곳에 상어가 두 마리 이상이면
                if (arr[i][j] >= 2)
                {
                    // vv 벡터는 같은 곳에 있는 상어들의 무게, 무게는 모든 상어마다 다르므로 인덱스로 활용 가능
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

