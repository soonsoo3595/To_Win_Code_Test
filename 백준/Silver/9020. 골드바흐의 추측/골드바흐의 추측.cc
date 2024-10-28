#include <bits/stdc++.h>

using namespace std;

int T, n;
bool prime[10004];

void Check()
{
    for (int i = 2; i <= 10000; i++)
    {
        for (int j = i * 2; j <= 10000; j += i)
        {
            prime[j] = false;
        }
    }
}

int main()
{
    cin >> T;

    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    Check();

    while (T--)
    {
        cin >> n;

        int left = 0;
        int right = 0;
        
        for (int i = n; i >= n / 2; i--)
        {
            if (prime[i] && prime[n - i])
            {
                left = n - i;
                right = i;
            }
        }

        cout << left << " " << right << '\n';
    }

    return 0;
}
