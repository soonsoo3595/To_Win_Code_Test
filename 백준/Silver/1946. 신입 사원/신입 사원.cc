#include <bits/stdc++.h>
using namespace std;

int T, N;

void Input()
{
	cin >> T;
}

void Solve()
{
	
	while(T--)
	{
		cin >> N;

		vector<pair<int, int>> v;
		for (int i = 0; i < N; i++)
		{
			int s1, s2;
			cin >> s1 >> s2;
			v.push_back({ s1, s2 });
		}

		sort(v.begin(), v.end());

		int temp = 0;
		int answer = 1;		// 1등 우선 선발

		for (int i = 1; i < N; i++)
		{
			if (v[temp].second > v[i].second)
			{
				answer++;
				temp = i;
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