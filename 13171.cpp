#include <bits/stdc++.h>

using namespace std;

long long A, X;
long long arr[65]; // arr[i] = A^i;
const long long MOD = 1000000007;

int main()
{
    cin >> A >> X;

    arr[0] = A % MOD;

    for (int i = 1; i <= 64; i++)
    {
        arr[i] = (arr[i - 1] * arr[i - 1]) % MOD;
    }

    long long answer = 1;

    vector<int> v;

    while (X > 1)
    {
        v.push_back(X % 2);
        X /= 2;
    }

    if (X == 1)
        v.push_back(1);

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
            answer = (answer * arr[i]) % MOD;
        }
    }

    cout << answer;

    return 0;
}

