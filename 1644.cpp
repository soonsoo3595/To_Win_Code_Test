#include <bits/stdc++.h>

using namespace std;

int N;
bool arr[4000004];
vector<int> v;

void Func()
{
    for (int i = 2; i <= N; i++)
    {
        for (int j = i * 2; j <= N; j += i)
        {
            if (arr[j]) continue;
            arr[j] = true;
        }
    }
}

int main()
{
    cin >> N;

    Func();

    for (int i = 2; i <= N; i++)
    {
        if (!arr[i]) v.push_back(i);
    }

    int answer = 0;
    int sum = 0;

    for (int i = (int)v.size() - 1; i >= 0; i--)
    {
        int idx = i;

        while (idx >= 0 && sum < N)
        {
            sum += v[idx--];
        }

        if (sum == N)
        {
            answer++;
        }

        sum = 0;
    }

    cout << answer;

    return 0;
}

