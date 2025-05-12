#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[104];
int arr2[104];

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

}

void Solve()
{
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int gender, number;
		cin >> gender >> number;

		if (gender == 1)
		{
			for (int i = number; i <= N; i += number)
			{
				arr[i] = 1 - arr[i];
			}
		}
		else if (gender == 2)
		{
			arr[number] = 1 - arr[number];

			for (int i = 1; number - i >= 1 && number + i <= N; i++)
			{
				if (arr[number - i] == arr[number + i])
				{
					arr[number - i] = 1 - arr[number - i];
					arr[number + i] = 1 - arr[number + i];
				}
				else
				{
					break;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << arr[i] << ' ';
		if (i % 20 == 0)
			cout << '\n';
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
