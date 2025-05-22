#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[200004];
int num[100004];
int answer;

void Input() 
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

void Solve()
{
	int left = 0, right = 0;
	int len = 0;

	while (right < N)
	{
		if (num[arr[right]] < K)
		{
			len++;
			num[arr[right]]++;
			right++;
		}
		else
		{
			len--;
			num[arr[left]]--;
			left++;
		}

		answer = max(answer, len);
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