#include <bits/stdc++.h>

using namespace std;

int A, B, C;
int arr[101];
int arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	for (int i = 0; i < 3; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		
		// 처음에는 도착 시간을 포함시켰어서 틀렸었다
		for (int j = t1; j < t2; j++)
		{
			arr[j]++;
		}
	}

	for (int i : arr)
	{
		if (i == 1)
			arr += A;
		else if (i == 2)
			arr += (2 * B);
		else if (i == 3)
			arr += (3 * C);
	}

	cout << arr;

	return 0;
}