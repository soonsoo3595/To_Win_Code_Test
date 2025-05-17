#include <bits/stdc++.h>
using namespace std;

int first;
int answer_num;
vector<int> answer_vector;

void Input() 
{
	cin >> first;
}

void DFS(int a, int b, vector<int>& v)
{
	if (a - b < 0)
	{
		if (answer_num < v.size())
		{
			answer_num = v.size();
			answer_vector.clear();

			for (int i = 0; i < answer_num; i++)
			{
				answer_vector.push_back(v[i]);
			}
		}

		return;
	}

	v.push_back(a - b);
	DFS(b, a - b, v);
}

void Solve() 
{
	for (int i = 1; i <= 30000; i++)
	{
		if (i > first) continue;

		vector<int> v;
		v.push_back(first);
		v.push_back(i);

		DFS(first, i, v);
	}

	cout << answer_num << '\n';

	for (int num : answer_vector)
	{
		cout << num << ' ';
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