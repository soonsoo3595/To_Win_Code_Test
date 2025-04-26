#include <bits/stdc++.h>
using namespace std;

int N;
int answer;

struct Room
{
	int start;
	int end;
};

vector<Room> v;

bool Compare(Room& r1, Room& r2)
{
	if (r1.end == r2.end)
		return r1.start < r2.start;

	return r1.end < r2.end;
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back({ start, end });
	}
}

void Solve()
{
	sort(v.begin(), v.end(), Compare);

	int end = 0;

	for (int i = 0; i < N; i++)
	{
		if (v[i].start >= end)
		{
			answer++;
			end = v[i].end;
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
