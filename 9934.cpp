#include <bits/stdc++.h>

using namespace std;

int K;
vector<int> v;
vector<int> answer[10];

void Func(int left, int right, int level)
{
    int mid = (left + right) / 2;
    answer[level].push_back(v[mid]);

    if (left >= right)
    {
        return;
    }

    Func(left, mid - 1, level + 1);
    Func(mid + 1, right, level + 1);
}



int main()
{
    cin >> K;

    for (int i = 0; i < pow(2, K) - 1; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }

    Func(0, v.size() - 1, 0);

    for (int i = 0; i < K; i++)
    {
        for (int node : answer[i])
        {
            cout << node << ' ';
        }
        cout << '\n';
    }
   
    return 0;
}

