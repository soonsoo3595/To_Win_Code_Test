#include <bits/stdc++.h>

using namespace std;

int T;
int n;
int arr[100004];
int visited[100004];
int check[100004];
int team_count;

void Input() 
{
	cin >> T;
}

void Func(int num)
{
	visited[num] = 1;
	int next = arr[num];

	if (visited[next] == 0)
	{
		Func(next);
	}
	// 아직 next의 DFS가 끝나지 않았을 때 -> 재귀 중임 -> 사이클임
	else if (check[next] == 0)
	{
		for (int i = next; i != num; i = arr[i])
			team_count++;
		team_count++;
	}

	check[num] = 1;
}

void Solve()
{
	while (T--)
	{
		memset(visited, 0, sizeof(visited));
		memset(check, 0, sizeof(check));
		team_count = 0;

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 0)
			{
				Func(i);
			}
		}

		cout << n - team_count << '\n';
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
