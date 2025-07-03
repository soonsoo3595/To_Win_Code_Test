#include <bits/stdc++.h>

using namespace std;

int T, N, M;

void Input()
{
	cin >> T;
}

void Solve()
{
	while (T--)
	{
		cin >> N >> M;

		long long answer = 1;
		int j = 1;

		for (int i = M; i > M - N; i--)
		{
			answer *= i;
			answer /= j++;
		}

		cout << answer << '\n';
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}
