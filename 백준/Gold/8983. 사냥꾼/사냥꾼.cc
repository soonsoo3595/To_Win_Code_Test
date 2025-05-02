#include <bits/stdc++.h>
using namespace std;

int M, N, L;
vector<int> arr;
vector<pair<int, int>> v;
int answer;

void Input()
{
	cin >> M >> N >> L;

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
}

void Solve()
{
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		if (v[i].second > L) continue;

		int dist = L - v[i].second;
		int left = v[i].first - dist;
		int right = v[i].first + dist;

		auto it = lower_bound(arr.begin(), arr.end(), left);

		if (it != arr.end() && *it <= right)
		{
			answer++;
		}
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
