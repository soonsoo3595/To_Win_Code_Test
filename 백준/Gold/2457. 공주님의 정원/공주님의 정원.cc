#include <bits/stdc++.h>
using namespace std;

int N;


struct Date
{
	int M;
	int D;

	bool operator<(const Date& other) const {
		return M == other.M ? D < other.D : M < other.M;
	}

	bool operator<=(const Date& other) const {
		return M < other.M || (M == other.M && D <= other.D);
	}

	bool operator>(const Date& other) const {
		return M > other.M || (M == other.M && D > other.D);
	}
};

struct Flower
{
	Date start;
	Date end;
};

vector<Flower> v;

bool Compare(const Flower& f1, const Flower& f2) {
	if (f1.start.M == f2.start.M && f1.start.D == f2.start.D)
		return f1.end > f2.end;
	return f1.start < f2.start;
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M1, D1, M2, D2;
		cin >> M1 >> D1 >> M2 >> D2;
		v.push_back({{M1, D1}, {M2, D2}});
	}
}

void Solve()
{
	sort(v.begin(), v.end(), Compare);

	int count = 0;
	Date cur = { 3, 1 };
	Date target = { 12, 1 };
	
	for (int i = 0; i < N;)
	{
		Date maxEnd = cur;
		bool found = false;

		while (i < N && v[i].start <= cur)
		{
			if (v[i].end > maxEnd)
			{
				maxEnd = v[i].end;
				found = true;
			}
			++i;
		}

		if (!found)
		{
			cout << 0 << '\n';
			return;
		}

		cur = maxEnd;
		++count;

		if (target <= cur)
		{
			break;
		}
	}

	if (cur < target)
	{
		cout << 0 << '\n';
	}
	else
	{
		cout << count << '\n';
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
