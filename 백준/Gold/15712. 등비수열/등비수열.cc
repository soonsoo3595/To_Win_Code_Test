#include <bits/stdc++.h>

using namespace std;

long long a, r, n, mod;
long long answer;

void Input() 
{
	cin >> a >> r >> n >> mod;
}

long long POW(long long A, long long B)
{
	if (B == 0)
	{
		return 1;
	}

	long long half = POW(A, B / 2);
	long long num = (half * half) % mod;

	if (B % 2)
	{
		num = (num * A) % mod;
	}


	return num % mod;
}

long long Func(long long r, long long n)
{
	if (n == 1) return 1;

	if (n % 2)
	{
		return ((Func(r, n / 2) * (1 + POW(r, n / 2))) % mod + POW(r, n - 1)) % mod;
	}
	else
	{
		return (Func(r, n / 2) * (1 + POW(r, n / 2))) % mod;
	}
}

void Solve()
{
	cout << (a * Func(r, n) % mod);
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}
