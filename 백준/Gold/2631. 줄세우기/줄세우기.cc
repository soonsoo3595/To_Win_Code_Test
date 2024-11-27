#include <bits/stdc++.h>
using namespace std;

int N;
int arr[204];

void Input()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];
}

void Solve()
{
    vector<int> LIS;
    LIS.push_back(arr[1]);

    for (int i = 2; i <= N; i++)
    {
        auto index = lower_bound(LIS.begin(), LIS.end(), arr[i]);

        // arr[i]보다 크거나 같은 값이 없을 때 추가
        if (index == LIS.end())
        {
            LIS.push_back(arr[i]);
        }
        else
        {
            *index = arr[i];
        }
    }
    
    cout << N - LIS.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}
