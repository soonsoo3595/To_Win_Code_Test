#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[100004];

int mx = 0;

bool check(int money)
{
    if (money < mx)  return false;

    int temp = money;
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        if (temp - arr[i] < 0)
        {
            temp = money;
            cnt++;
        }

        temp -= arr[i];
    }

    if (temp != money)   cnt++;

    return cnt <= M;
}

int main()
{
    cin >> N >> M;

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        mx = max(mx, arr[i]);
    }

    int low = 0, high = sum;
    int K = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (check(mid))
        {
            high = mid - 1;
            K = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << K;

    return 0;
}

