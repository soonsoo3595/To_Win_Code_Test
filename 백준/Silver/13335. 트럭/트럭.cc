#include <bits/stdc++.h>
using namespace std;

int n, w, L;
int arr[1004];

void Input()
{
	cin >> n >> w >> L;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void Solve()
{
	queue<int> q1;
	queue<int> bridge;
	int weight = 0;
	int time = 0;

	for (int i = 0; i < n; i++)
	{
		q1.push(arr[i]);
	}

	for (int i = 0; i < w; i++)
	{
		bridge.push(0);
	}

	while (!q1.empty() || weight > 0)
	{
		time++;

		weight -= bridge.front();
		bridge.pop();

		if (!q1.empty())
		{
			if (weight + q1.front() <= L)
			{
				int truck = q1.front();
				q1.pop();
				bridge.push(truck);
				weight += truck;
			}
			else
			{
				bridge.push(0); 
			}
		}
		else
		{
			bridge.push(0); 
		}
	}

	cout << time << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}