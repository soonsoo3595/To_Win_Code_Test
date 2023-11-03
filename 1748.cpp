#include <bits/stdc++.h>

using namespace std;

int N;
int answer;

int main()
{
    cin >> N;

    int square_ten = 10;
    bool flag = true;

    while(flag)
    {
        if ((N / square_ten) == 0)
            flag = false;

        if (N >= square_ten)
        {
            answer += (((square_ten - 1) - (square_ten / 10) + 1) * log10(square_ten));
        }
        else
        {
            answer += ((N - (square_ten / 10) + 1) * log10(square_ten));
        }

        square_ten *= 10;
    }

    cout << answer;

    return 0;
}

