#include <bits/stdc++.h>

using namespace std;

int main()
{
	// ������������ �����ؾ� �� {2, 1, 3}�� ��� ����� �� �ȵ�
	// int a[] = { 1, 2, 3 };

	vector<int> a = { 2, 1, 3, 100, 200 };
	sort(a.begin(), a.end());

	do
	{
		// for (int i : a) cout << i << " ";
		// ���� ��� �ߺ��ǰ� ���� 1 2 3 100 200 / 1 2 3 200 100
		for (int i = 0; i < 2; i++) cout << a[i] << " ";

		cout << '\n';
	} while (next_permutation(a.begin(), a.end()));

	return 0;
}