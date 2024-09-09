#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;

bool compare(pair<int, int>& p1, pair<int, int>& p2)
{
	return p1.second < p2.second;
}

int main()
{
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	while (n--)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}

	sort(v.begin(), v.end(), compare);

	for (auto p : v)
	{
		pq.push(p.first);

		if (pq.size() > p.second)
		{
			pq.pop();
		}
	}

	int sum = 0;
	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}

	cout << sum;
}