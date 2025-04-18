#include <bits/stdc++.h>
using namespace std;

void Input()
{

}

void Combi(int start, vector<int>& v1, vector<int>& v2)
{
	if (v2.size() == 6)
	{
		for (int num : v2)
		{
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}

	int size = v1.size();
	for (int i = start; i < size; i++)
	{
		v2.push_back(v1[i]);
		Combi(i + 1, v1, v2);
		v2.pop_back();
	}
}

void Solve()
{
	while (true)
	{
		int k;
		cin >> k;
		if (k == 0) break;

		vector<int> v1;
		for (int i = 0; i < k; i++)
		{
			int temp;
			cin >> temp;
			v1.push_back(temp);
		}

		vector<int> v2;
		Combi(0, v1, v2);
		cout << '\n';
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