#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100004];

void Input() 
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

void Solve()
{
	priority_queue<int, vector<int>, greater<>> pq;

	for (int i = 0; i < N; i++)
	{
		pq.push(arr[i]);
	}

	int answer = 0;
	while (pq.size() > 1)
	{
		int A = pq.top(); pq.pop();
		int B = pq.top(); pq.pop();
		int sum = A + B;
		answer += sum;
		pq.push(sum);
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
