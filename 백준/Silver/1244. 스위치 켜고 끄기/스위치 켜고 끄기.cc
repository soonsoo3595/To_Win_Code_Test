#include <bits/stdc++.h>

using namespace std;

int N;
int arr[104];

int T;

void Boy(int num)
{
    for (int i = num; i <= N; i += num)
    {
        arr[i] = 1 - arr[i];
    }
}

void Girl(int num)
{
    vector<int> v;
    v.push_back(num);

    arr[num] = 1 - arr[num];

    for (int i = 1; num - i >= 1 && num + i <= N; i++)
    {
        if (arr[num - i] == arr[num + i])
        {
            arr[num - i] = 1 - arr[num - i];
            arr[num + i] = 1 - arr[num + i];
        }
        else
        {
            break;
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    cin >> T;

    while (T--)
    {
        int gender, num;
        cin >> gender >> num;

        if (gender == 1)
        {
            Boy(num);
        }
        else if (gender == 2)
        {
            Girl(num);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }

    return 0;
}
