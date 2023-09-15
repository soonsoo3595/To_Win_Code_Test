#include <bits/stdc++.h>

using namespace std;

int main()
{
	// 오름차순으로 정렬해야 함 {2, 1, 3}의 경우 출력이 잘 안됨
	// int a[] = { 1, 2, 3 };

	vector<int> a = { 2, 1, 3, 100, 200 };
	sort(a.begin(), a.end());

	do
	{
		// for (int i : a) cout << i << " ";
		// 밑의 경우 중복되게 보임 1 2 3 100 200 / 1 2 3 200 100
		for (int i = 0; i < 2; i++) cout << a[i] << " ";

		cout << '\n';
	} while (next_permutation(a.begin(), a.end()));

	return 0;
}