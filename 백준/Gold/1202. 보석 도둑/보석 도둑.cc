#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> jewels;
vector<int> bags;

void Input() 
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int M, V;
		cin >> M >> V;
		jewels.push_back({ M, V });
	}

	for (int i = 0; i < K; i++)
	{
		int C;
		cin >> C;
		bags.push_back(C);
	}
}

void Solve()
{
	sort(jewels.begin(), jewels.end());
	sort(bags.begin(), bags.end());

	priority_queue<int> pq;
	int idx = 0;
	long long answer = 0;

	for (int i = 0; i < K; i++)
	{
		while (idx < N && jewels[idx].first <= bags[i])
		{
			pq.push(jewels[idx].second);
			++idx;
		}

		if (!pq.empty())
		{
			answer += pq.top();
			pq.pop();
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
