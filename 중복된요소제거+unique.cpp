#include <bits/stdc++.h>

using namespace std;

/*
	���׿��� ���� ����
	
	�ߺ��� ��� ����
	1. map ���
	2. count �迭 �����
	3. unique �Լ� ��� -> sort�� �Բ� ����
*/

map<int, int> mp;

int main()
{
	/* 1 ����
	vector<int> v{ 1, 1, 2, 2, 3, 3 };
	for (int i : v)
	{
		if (mp[i])
		{
			continue;
		}
		else
		{
			mp[i] = 1;
		}
	}
	vector<int> ret;

	for (auto it : mp)
	{
		ret.push_back(it.first);
	}

	for (int i : ret) cout << i << '\n';
	*/

#pragma region unique�Լ�

	/* unique �Լ� ����
	for (int i = 1; i <= 5; i++)
	{
		v.push_back(i);
		v.push_back(i);
	}
	for (int i : v) cout << i << " ";
	cout << '\n';
	// �ߺ����� ���� ��ҷ� ä�� ��, �� ���� ���ͷ����͸� ��ȯ�Ѵ�.
	auto it = unique(v.begin(), v.end());
	cout << it - v.begin() << '\n';	// 5�� ���
	// �տ��� ���� �ߺ����� �ʰ� ä�� �� ������ ��ҵ��� �״�� �д�.
	for (int i : v) cout << i << " ";
	cout << '\n';
	*/

	vector<int> v{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 8, 9 };
	// 1 2 3 4 5 6 7 8 9 
	sort(v.begin(), v.end());
	unique(v.begin(), v.end());

	// v.erase(unique(v.begin(), v.end()), v.end());
	for (int i : v) cout << i << " ";
	cout << '\n';
	return 0;
#pragma endregion

}