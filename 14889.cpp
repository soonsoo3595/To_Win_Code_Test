#include <bits/stdc++.h>

using namespace std;

int N;
int arr[21][21];
int team[21];
int answer = INT_MAX;

void Func2()
{
    vector<int> start, link;

    for (int i = 1; i <= N; i++)
    {
        if (team[i] == 1)
        {
            start.push_back(i);
        }
        else
        {
            link.push_back(i);
        }
    }

    int start_stat = 0;

    for (int i = 0; i < start.size(); i++)
    {
        for (int j = i + 1; j < start.size(); j++)
        {
            start_stat += arr[start[i]][start[j]];
            start_stat += arr[start[j]][start[i]];
        }
    }

    int link_stat = 0;

    for (int i = 0; i < link.size(); i++)
    {
        for (int j = i + 1; j < link.size(); j++)
        {
            link_stat += arr[link[i]][link[j]];
            link_stat += arr[link[j]][link[i]];
        }
    }

    answer = min(answer, abs(start_stat - link_stat));
}

void Func(int start, int depth)
{
    if (depth == N / 2)
    {
        Func2();
        return;
    }

    for (int i = start; i <= N; i++)
    {
        team[i] = 1;
        Func(i + 1, depth + 1);
        team[i] = 0;
    }
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }

    Func(1, 0);

    cout << answer;

    return 0;
}

