#include <bits/stdc++.h>

using namespace std;

int T;

void Input()
{
	cin >> T;
}

void Solve()
{
	while (T--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;

		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			int cx, cy, r;
			cin >> cx >> cy >> r;

			int dist_start = pow((cx - x1), 2) + pow((cy - y1), 2);
			int dist_end = pow((cx - x2), 2) + pow((cy - y2), 2);

			if ((dist_start < r * r) ^ (dist_end < r * r))
			{
				cnt++;
			}
		}

		cout << cnt << '\n';
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
