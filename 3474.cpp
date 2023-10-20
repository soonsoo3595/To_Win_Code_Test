#include <bits/stdc++.h>

using namespace std;

int T, N;
int answer;
// arr의 각 요소는 5가 몇 개 들어가있는지 
int arr[20000001];

int DP(int num)
{
    if (arr[num])
        return arr[num];

    if ((num * 5) % 5 == 0)
    {
        arr[num] = 1 + DP(num / 5);
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        cin >> N;
        answer = 0;

        for (int i = 1; i <= N / 5; i++)
        {
            DP(i);
        }

        for (int i = 1; i <= N / 5; i++)
        {
            answer += arr[i];
        }

        cout << answer << '\n';
    }

    return 0;
}

