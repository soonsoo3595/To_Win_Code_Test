#include <bits/stdc++.h>

using namespace std;

int D, K;
int dpX[31];
int dpY[31];

int main()
{
    cin >> D >> K;

    dpX[0] = 0; dpX[1] = 1; dpX[2] = 0;
    dpY[0] = 0; dpY[1] = 0; dpY[2] = 1;

    for (int i = 3; i <= D; i++)
    {
        dpX[i] = dpX[i - 1] + dpX[i - 2];
        dpY[i] = dpY[i - 1] + dpY[i - 2];
    }

    for (int i = 1; i <= K / dpX[D]; i++)
    {
        for (int j = 1; j <= K / dpY[D]; j++)
        {
            if (i * dpX[D] + j * dpY[D] == K)
            {
                cout << i << '\n' << j;
                return 0;
            }
        }
    }



    return 0;
}

