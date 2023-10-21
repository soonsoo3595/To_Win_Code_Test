#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr1[104], arr2[104];
int visited[104];
int answer = 0;

void func1(int pos)
{
    visited[pos] = 1;

    int dpos[] = { -M, 1, M, -1 };

    // 바이러스가 왼쪽 끝, 오른쪽 끝에 있을때 예외처리(왼쪽 못가게 오른쪽 못가게)
    for (int i = 0; i < 4; i++)
    {
        if (pos % M == 0 && i == 3)
            continue;
        else if ((pos + 1) % M == 0 && i == 1)
            continue;

        int npos = pos + dpos[i];

        if (npos < 0 || npos >= N * M) continue;
        if (arr2[npos] != 0 || visited[npos]) continue;

        arr2[npos] = 2;
        func1(npos);
    }

    return;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N * M; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < N * M; i++)
    {
        for (int j = i + 1; j < N * M; j++)
        {
            for (int k = j + 1; k < N * M; k++)
            {
                if (arr1[i] != 0 || arr1[j] != 0 || arr1[k] != 0)
                    continue;

                memcpy(arr2, arr1, sizeof(arr1));

                int count = 0;

                arr2[i] = 1; arr2[j] = 1; arr2[k] = 1;

                // 바이러스 퍼짐
                for (int pos = 0; pos < N * M; pos++)
                {
                    if (arr2[pos] == 2 && !visited[pos])
                        func1(pos);
                }

                // 안전구역 찾기
                for (int pos = 0; pos < N * M; pos++)
                {
                    if (arr2[pos] == 0)
                    {
                        count++;
                    }
                }
                answer = max(answer, count);

                memset(visited, 0, sizeof(visited));

            }
        }
    }
    
    cout << answer;

    return 0;
}

