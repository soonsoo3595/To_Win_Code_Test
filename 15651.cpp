#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr;

void Print()
{
    for (int num : arr)
    {
        cout << num << ' ';
    }

    cout << '\n';
}

void Go(int depth)
{
    if (depth == M)
    {
        Print();
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        arr.push_back(i);
        Go(depth + 1);
        arr.pop_back();
    }
}

int main()
{
    cin >> N >> M;

    Go(0);

    return 0;
}

