#include <bits/stdc++.h>

using namespace std;

long long T, N;

int main()
{
    cin >> T;

    while (T--)
    {
        cin >> N;

        long long left = 1;
        long long right = (long long)1e9;
        
        long long answer = 0;

        while (left <= right)
        {
            long long mid = (left + right) / 2;

            if (mid * (mid + 1) / 2 > N)
            {
                right = mid - 1;
            }
            else
            {
                answer = mid;
                left = mid + 1;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
