#include <bits/stdc++.h>
using namespace std;

int K, L;
vector<string> wait;
map<string, int> student;


void Input() 
{
	cin >> K >> L;

	for (int i = 0; i < L; i++)
	{
		string s;
		cin >> s;
		wait.push_back(s);
	}
}

void Solve()
{
	for (int i = 0; i < L; i++)
	{
		const string id = wait[i];
		if (student.find(id) != student.end())
		{
			student.erase(id);
		}

		student.insert({ id, i });
	}

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