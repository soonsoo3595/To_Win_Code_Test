#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr;
int visited[9];

void Print()
{
    for (int num : arr)
    {
        cout << num << ' ';
    }

    cout << '\n';
}

void Go(int start, int depth)
{
    if (depth == M)
    {
        Print();
        return;
    }

    for (int i = start; i <= N; i++)
    {
        arr.push_back(i);

        Go(i + 1, depth + 1);

        arr.pop_back();
    }
}

int main()
{
    cin >> N >> M;

    Go(1, 0);

    return 0;
}
