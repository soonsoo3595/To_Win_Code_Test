#include <bits/stdc++.h>

using namespace std;

/*
	코테에서 많이 나옴
	
	중복된 요소 제거
	1. map 사용
	2. count 배열 만들기
	3. unique 함수 사용 -> sort와 함께 쓰기
*/

map<int, int> mp;

int main()
{
	/* 1 예제
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

#pragma region unique함수

	/* unique 함수 예제
	for (int i = 1; i <= 5; i++)
	{
		v.push_back(i);
		v.push_back(i);
	}
	for (int i : v) cout << i << " ";
	cout << '\n';
	// 중복되지 않은 요소로 채운 후, 그 다음 이터레이터를 반환한다.
	auto it = unique(v.begin(), v.end());
	cout << it - v.begin() << '\n';	// 5를 출력
	// 앞에서 부터 중복되지 않게 채운 후 나머지 요소들은 그대로 둔다.
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