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

void Go(int depth)
{
    if (depth == M)
    {
        Print();
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr.push_back(i);

            Go(depth + 1);

            visited[i] = false;
            arr.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;

    Go(0);

    return 0;
}

