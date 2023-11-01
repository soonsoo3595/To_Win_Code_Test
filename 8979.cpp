#include <bits/stdc++.h>

using namespace std;

int N, K;

struct Country
{
	int index;
	int gold;
	int silver;
	int bronze;
	int rank;
	bool flag;

	Country(int index, int gold, int silver, int bronze)
	{
		this->index = index;
		this->gold = gold;
		this->silver = silver;
		this->bronze = bronze;
		rank = 0;
		flag = false;
	}
};

vector<Country> v;

bool Compare(Country& c1, Country& c2)
{
	if (c1.gold == c2.gold)
	{
		if (c1.silver == c2.silver)
		{
			if (c1.bronze == c2.bronze)
			{
				c1.flag = true; c2.flag = true;
				return c1.index < c2.index;
			}
			else
			{
				return c1.bronze > c2.bronze;
			}
		}
		else
		{
			return c1.silver > c2.silver;
		}
	}
	else
	{
		return c1.gold > c2.gold;
	}
}

int main()
{
	cin >> N >> K;

	while (N--)
	{
		int n1, n2, n3, n4;

		cin >> n1 >> n2 >> n3 >> n4;

		Country c(n1, n2, n3, n4);
		v.push_back(c);
	}


	sort(v.begin(), v.end(), Compare);

	for (int i = 0; i < v.size(); i++)
	{
		v[i].rank = i + 1;
	}

	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i].flag && v[i + 1].flag)
		{
			v[i + 1].rank = v[i].rank;
		}
		else if (v[i].flag && !v[i + 1].flag)
		{
			v[i + 1].rank = i + 2;
		}
	}

	for (auto c : v)
	{
		if(c.index == K)
			cout << c.rank << '\n';
	}

    return 0;
}

