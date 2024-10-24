#include <bits/stdc++.h>

using namespace std;

int N, S;
int arr[21];
vector<int> v;
int answer;

void Print()
{
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << '\n';
}

void Func(int start, int size)
{
    if (size == v.size())
    {
        if (accumulate(v.begin(), v.end(), 0) == S)
        {
            answer++;
        }

        return;
    }

    for (int i = start; i <= N; i++)
    {
        v.push_back(arr[i]);
        Func(i + 1, size);
        v.pop_back();
    }
}

int main()
{
    cin >> N >> S;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        Func(1, i);
    }

    cout << answer;

    return 0;
}
