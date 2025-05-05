#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100004];

void Input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void Solve()
{
	stack<int> s;
	string answer;
	int cur = 1; int idx = 0;

	while (idx < n)
	{
		if (!s.empty() && s.top() == arr[idx])
		{
			s.pop();
			answer += '-';
			++idx;
		}
		else if (cur <= n)
		{
			s.push(cur++);
			answer += '+';
		}
		else
		{
			cout << "NO\n";
			return;
		}
	}

	for (char c : answer)
	{
		cout << c << '\n';
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
