#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100004];
int length[100004];

void Input() 
{
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> length[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

void Solve()
{
	long long total = 0;
	long long minPrice = arr[0];

	for (int i = 0; i < N - 1; i++)
	{
		if (arr[i] < minPrice)
		{
			minPrice = arr[i];
		}

		total += minPrice * length[i];
	}

	cout << total;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}
