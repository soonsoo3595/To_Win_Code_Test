#include <bits/stdc++.h>
using namespace std;

int N;
int arr[104];
bool visited[104];

vector<int> answer_vector;

void Input() 
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
}

void DFS(int start, int current)
{
	if (visited[current])
	{
		if (start == current)
		{
			answer_vector.push_back(current);
		}

		return;
	}

	visited[current] = true;
	DFS(start, arr[current]);
}

void Solve() 
{
	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited));
		DFS(i, i);
	}

	cout << answer_vector.size() << '\n';
	sort(answer_vector.begin(), answer_vector.end());

	for (int num : answer_vector)
	{
		cout << num << '\n';
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