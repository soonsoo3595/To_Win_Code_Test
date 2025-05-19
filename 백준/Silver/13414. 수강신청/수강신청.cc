#include <bits/stdc++.h>
#include "unordered_map"

using namespace std;

int K, L;
unordered_map<string, int> student;

void Input() 
{
	cin >> K >> L;

	for (int i = 0; i < L; i++)
	{
		string s;
		cin >> s;
		student[s] = i;
	}
}

void Solve()
{
	vector<pair<string, int>> v(student.begin(), student.end());
	sort(v.begin(), v.end(), [](auto& a1, auto& a2)
		{
			return a1.second < a2.second;
		});

	for (int i = 0; i < K; i++)
	{
		if (i >= v.size()) break;

		cout << v[i].first << '\n';
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