#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000004];
int NGE[1000004];
stack<int> s;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

void Solve()
{
	for (int i = N - 1; i >= 0; i--)
	{
		while (!s.empty() && s.top() <= arr[i])
		{
			s.pop();
		}

		if (s.empty())
		{
			NGE[i] = -1;
		}
		else
		{
			NGE[i] = s.top();
		}

		s.push(arr[i]);
	}

	for (int i = 0; i < N; i++)
	{
		cout << NGE[i] << ' ';
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
