#include <bits/stdc++.h>

using namespace std;

int T;
int M, N, x, y;
int answer;

int main()
{
    cin >> T;

    while (T--)
    {
        cin >> M >> N >> x >> y;

        answer = -1;

        for (int year = x; year <= M * N; year += M)
        {
            if (((year % N) == 0 ? N : year % N) == y)
            {
                answer = year;
                break;
            }
        }

        cout << answer << '\n';
    }

    return 0;

}

