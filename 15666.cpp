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

void Go(int start, int depth)
{
    if (depth == M)
    {
        Print();
        return;
    }

    int last = 0;

    for (int i = start; i < N; i++)
    {
        if (last != arr[i])
        {
            sequence.push_back(arr[i]);
            last = arr[i];
            Go(i, depth + 1);
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

    Go(0, 0);

    return 0;
}

