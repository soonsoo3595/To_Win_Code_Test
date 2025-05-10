#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[51][51];
int answer = INT_MAX;

vector<pair<int, int>> v1;  // 집
vector<pair<int, int>> v2;  // 치킨집
vector<pair<int, int>> v3;  // 남길 치킨 집

int distance(pair<int, int> p1, pair<int, int> p2)
{
    int d1 = abs(p2.first - p1.first);
    int d2 = abs(p2.second - p1.second);

    return d1 + d2;
}

void go(int num)
{
    if (v3.size() == M)
    {
        int sum = 0;

        for (int i = 0; i < v1.size(); i++)
        {
            int num = INT_MAX;

            for (auto p : v3)
            {
                num = min(num, distance(p, v1[i]));
            }

            sum += num;
        }

        answer = min(answer, sum);

        return;
    }

    for (int i = num + 1; i < v2.size(); i++)
    {
        v3.push_back(v2[i]);
        go(i);
        v3.pop_back();
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input;
            cin >> input;

            if (input == 1)
                v1.push_back({ i, j });
            else if (input == 2)
                v2.push_back({ i, j });

            arr[i][j] = input;

        }
    }
    
    for (int i = 0; i < v2.size(); i++)
    {
        v3.push_back(v2[i]);
        go(i);
        v3.clear();
    }

    cout << answer;

    return 0;
}

