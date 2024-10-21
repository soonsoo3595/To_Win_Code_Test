#include <bits/stdc++.h>

using namespace std;

long long A, B, C;

long long func(int A, int B)
{
    if (B == 0)
        return 1;

    long long half = func(A, B / 2);
    half = (half * half) % C;

    if (B % 2 == 1)
        half = (half * A) % C;

    return half;
}

int main()
{
    cin >> A >> B >> C;

    cout << func(A, B);

    return 0;
}

