#include <bits/stdc++.h>
using namespace std;

long long N, M;
long long arr[1000001];
long long tree_max;

void Input() 
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
		tree_max = max(tree_max, arr[i]);
    }
}

void Solve()
{
    long long low = 0;
    long long high = tree_max;

    while (low <= high)
    {
		long long mid = (low + high) / 2;

		long long sum = 0;
        for (int i = 0; i < N; i++)
        {
			if (arr[i] > mid)
				sum += arr[i] - mid;
        }

		if (sum >= M)
			low = mid + 1;
		else
			high = mid - 1;
    }

    cout << high;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Solve();

    return 0;
}