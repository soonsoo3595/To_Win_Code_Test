#include <bits/stdc++.h>

using namespace std;

long long A, B;

long long Go(long long num, long long count)
{
    if (num == B)
    {
        return count;
    }
    else if (num > B)
    {
        return INT_MAX;
    }

    return min(Go(num * 2, count + 1), Go(num * 10 + 1, count + 1));
}

int main()
{
    cin >> A >> B;

    long long answer = 0;
    answer = Go(A, 0);

    if (answer == INT_MAX)
        cout << -1;
    else
        cout << answer + 1;

    return 0;
}

