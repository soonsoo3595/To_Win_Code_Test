#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[10004];
int answer;

void Input() 
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

void Solve()
{
	int left = 0, right = 0;
	int sum = arr[0];

	while (right < N)
	{
		if (sum == M)
		{
			answer++;
			sum += arr[++right];
		}
		else if(sum > M)
		{
			sum -= arr[left++];
		}
		else if (sum < M)
		{
			sum += arr[++right];
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