#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> computer[10004];
vector<int> answer;

int Func(int num)
{
    if (computer[num].empty())
        return 0;

    int ret = 1;

    for (int there : computer[num])
    {
        ret += Func(there);
    }

    return ret;
}

int main()
{
    cin >> N >> M;

    int A, B;

    while (M--)
    {
        cin >> A >> B;

        computer[B].push_back(A);
    }
    
    int max = 0;

    for (int i = 1; i <= N; i++)
    {
        if (computer[i].empty())
            continue;

        int current = Func(i);

        if (max < current)
        {
            max = current;
            answer.clear();
            answer.push_back(i);
        }
        else if (max == current)
        {
            answer.push_back(i);
        }
    }

    sort(answer.begin(), answer.end());

    for (int num : answer)
    {
        cout << num << ' ';
    }

    return 0;
}

