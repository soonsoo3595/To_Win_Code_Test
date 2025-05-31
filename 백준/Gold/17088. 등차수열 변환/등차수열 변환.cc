#include <bits/stdc++.h>

using namespace std;

int N;
int B[100004];
int answer = INT_MAX;

void Input() 
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
}

void Solve()
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int b_0 = B[0] + i;
			int b_1 = B[1] + j;
			int d = b_1 - b_0;

			int cnt = abs(i) + abs(j);
			bool check = true;

			for (int k = 2; k < N; k++)
			{
				int b_k = b_0 + k * d;

				if (abs(B[k] - b_k) > 1)
				{
					check = false;
					break;
				}
				else if (B[k] != b_k)
				{
					cnt++;
				}
			}

			if (check) answer = min(answer, cnt);
		}
	}

	if (answer == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << answer;
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