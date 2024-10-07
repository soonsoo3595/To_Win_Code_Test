#include <bits/stdc++.h>

using namespace std;

int N;
long long width[81];
long long length[81];

int main()
{
    cin >> N;

    width[1] = 1;
    width[2] = 1;

    for (int i = 3; i <= N; i++)
    {
        width[i] = width[i - 1] + width[i - 2];
    }

    length[1] = 4;

    for (int i = 2; i <= N; i++)
    {
        length[i] = length[i - 1] + width[i] * 2;
    }

    cout << length[N];

    return 0;
}

