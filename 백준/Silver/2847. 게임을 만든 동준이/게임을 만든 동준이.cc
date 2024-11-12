#include <bits/stdc++.h>
using namespace std;

int N;
int arr[104];

void Input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

void Solve()
{
    int compare = 20004;
    int answer = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        if (arr[i] >= compare)
        {
            int value = compare - 1;
            answer += (arr[i] - value);
            arr[i] = value;
        }
        
        compare = arr[i];
    }

    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}
