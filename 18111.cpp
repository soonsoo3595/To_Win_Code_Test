#include <bits/stdc++.h>

using namespace std;

int N, M, B;
int arr[504][504];

int max_height = INT_MIN;
int min_height = INT_MAX;
int min_time = INT_MAX;

vector<pair<int, int>> answer;

void func(int height)
{
    int block = B;
    int time = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int gap = arr[i][j] - height;

            if (gap < 0)
            {
                block -= abs(gap);
                time += (1 * abs(gap));     // ½Ã°£À» ¿Ö ¾È°öÇØÁá³Ä!
            }
            else if(gap > 0)
            {
                block += abs(gap);
                time += (2 * abs(gap));
            }
        }
    }

    if (block >= 0)
    {
        if (time < min_time)
        {
            min_time = time;
            answer.clear();
            answer.push_back({ height, time });
        }
        else if (time == min_time)
        {
            answer.push_back({ height, time });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> B;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            max_height = max(max_height, arr[i][j]);
            min_height = min(min_height, arr[i][j]);
        }
    }

    for (int height = min_height; height <= max_height; height++)
    {
        func(height);
    }

    sort(answer.begin(), answer.end(), greater<pair<int, int>>());

    cout << answer[0].second << ' ' << answer[0].first;

    return 0;
}

