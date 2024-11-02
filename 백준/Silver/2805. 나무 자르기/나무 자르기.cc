#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	int max_height = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		max_height = max(max_height, temp);
		tree.push_back(temp);
	}

	int low, mid, high;

	low = 1; high = max_height;

	int ans = 0;

	while (low <= high)
	{
		long long cnt = 0;

		mid = (low + high) / 2;

		for (int i = 0; i < N; i++)
		{
			if (tree[i] <= mid)
				continue;

			cnt += (tree[i] - mid);
		}

		if (cnt >= M)
		{
			low = mid + 1;

			ans = max(ans, mid);
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << ans;

}