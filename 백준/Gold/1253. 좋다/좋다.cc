#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[2004];
int answer;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for (int i = 0; i < N; i++)
    {
        int left = 0;
        int right = N - 1;

        while (left < right)
        {
            if (left == i)
            {
                left++;
                continue;
            }
            if (right == i)
            {
                right--;
                continue;
            }

            if (arr[left] + arr[right] == arr[i])
            {
                answer++;
                break;
            }
            else if (arr[left] + arr[right] < arr[i])
            {
                left++;
            }
            else if (arr[left] + arr[right] > arr[i])
            {
                right--;
            }
        }
    }

    cout << answer;

    return 0;
}