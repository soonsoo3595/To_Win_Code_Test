#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> P;

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		P.push_back(temp);
	}
}

void Solve()
{
	sort(P.begin(), P.end());

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = 0; j <= i; j++)
		{
			sum += P[j];
		}

		answer += sum;
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

// 1 2 3 3 4
// 1 + (1 + 2) + (1 + 2 + 3) + (1 + 2 + 3 + 3) + (1 + 2 + 3 + 3 + 4)
// 1 + 3 + 6 + 9 + 13