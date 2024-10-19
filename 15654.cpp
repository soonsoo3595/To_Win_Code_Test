#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr;
vector<int> sequence;
int visited[9];

void Print()
{
    for (int num : sequence)
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

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            sequence.push_back(arr[i]);
            Go(depth + 1);
            visited[i] = false;
            sequence.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int input; cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    Go(0);

    return 0;
}

