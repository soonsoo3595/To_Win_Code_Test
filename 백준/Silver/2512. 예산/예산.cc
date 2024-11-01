#include <bits/stdc++.h>

using namespace std;

int N, M;
int money[100004];
int answer;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> money[i];
    }
    
    cin >> M;

    int left = 1;
    int right = *max_element(money, money + N);

    while (left <= right)
    {
        int mid = (left + right) / 2;

        int sum = 0;

        for (int i = 0; i < N; i++)
        {
            if (money[i] < mid)
            {
                sum += money[i];
            }
            else
            {
                sum += mid;
            }
        }

        if (sum > M)
        {
            right = mid - 1;
        }
        else
        {
            answer = mid;
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}
 