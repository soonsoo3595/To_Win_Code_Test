#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
int board[100001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void func(int x)
{
	queue<int> q;
	q.push(x);

	while (board[K] == -1)
	{
		int here = q.front();
		q.pop();

		for (int next : {here - 1, here + 1, 2 * here}) 
		{
			if (next < 0 || next > 100000) continue;
			if (board[next] != -1) continue;
			
			board[next] = board[here] + 1;
			q.push(next);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < 100001; i++)
		board[i] = -1;

	board[N] = 0;
	
	func(N);

	cout << board[K];

	return 0;
}