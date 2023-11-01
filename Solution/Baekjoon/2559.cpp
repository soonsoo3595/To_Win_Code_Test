// 叔鳶推にににににににに

#include <bits/stdc++.h>

using namespace std;

int N, K;
int psum[100004];
int answer = -987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	
	int prev = 0;

	for (int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;
		psum[i] = prev + input;
		prev = psum[i];
	}

	for(int i = 0; i <= N; i++)
		cout << psum[i] << ' ';

	cout << '\n';

	for (int i = 0; i <= N - K + 1; i++)
	{
		int sum = psum[i + K - 1] - psum[i];
		cout << sum << ' ';
		answer = max(sum, answer);
	}

	cout << answer;
}