#include <bits/stdc++.h>

using namespace std;

int N;
long long height[54];
int answer;

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> height[i];
	}
}

void Solve()
{
	for (int i = 0; i < N; i++) 
	{
		int cnt = 0;

		double maxSlope = -1e18;
		for (int j = i + 1; j < N; j++) 
		{
			double slope = (double)(height[j] - height[i]) / (j - i);
			if (slope > maxSlope) {
				maxSlope = slope;
				cnt++;
			}
		}

		double minSlope = 1e18;
		for (int j = i - 1; j >= 0; j--) 
		{
			double slope = (double)(height[j] - height[i]) / (j - i);
			if (slope < minSlope) {
				minSlope = slope;
				cnt++;
			}
		}

		answer = max(answer, cnt);
	}

	cout << answer;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}
