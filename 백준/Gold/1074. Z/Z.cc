#include <bits/stdc++.h>

using namespace std;

int N, r, c;

int main()
{
    cin >> N >> r >> c;

    long long answer = 0;

    while (N != 1)
    {
        answer = answer + pow(2, 2 * N - 1) * (r / (int)pow(2, N - 1));
        answer = answer + pow(2, 2 * N - 2) * (c / (int)pow(2, N - 1));

        r = r % (int)pow(2, N - 1);
        c = c % (int)pow(2, N - 1);

        N--;
    }

    answer = answer + 2 * r + c;

    cout << answer;

    return 0;
}

