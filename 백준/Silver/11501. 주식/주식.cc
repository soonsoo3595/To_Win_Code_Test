#include <bits/stdc++.h>
using namespace std;

int T, N;
int arr[1000004];

void Input()
{
	cin >> T;
}

void Solve()
{
	while (T--)
	{
		cin >> N;

		long long answer = 0;
		long long price_max = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}

		for (int i = N - 1; i >= 0; i--)
		{
			if (arr[i] >= price_max)
			{
				price_max = arr[i];
			}
			else
			{
				answer += (price_max - arr[i]);
			}
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
