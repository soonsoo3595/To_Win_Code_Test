#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> num;
int arr[8001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	
	// 0. 평균 구하기 전에 배열을 오름차순으로 먼저 정렬하자
	sort(num.begin(), num.end());

	// 1. 산술평균
	double sum = 0.0;

	for (int i = 0; i < N; i++)
	{
		sum += num[i];
	}

	cout << (int)(floor((sum / N) + 0.5)) << '\n';

	// 2. 중앙값
	// n은 홀수라 그냥 중앙 인덱스만 구하면됨
	int index = 0; // 중앙값이 있는 위치
	index = (N - 1) / 2;

	cout << num[index] << '\n';

	// 3. 최빈값

	for (int i = 0; i < N; i++)
	{
		arr[num[i] + 4000]++;
	}

	int count = 0;
	vector<int> mode;

	for (int i = 0; i <= 8000; i++)
	{
		if (arr[i] > count)
		{
			count = arr[i];
			continue;
		}
	}

	for (int i = 0; i <= 8000; i++)
	{
		if (arr[i] == count)
		{
			mode.push_back(i - 4000);
			continue;
		}
	}

	sort(mode.begin(), mode.end());

	if (mode.size() <= 1)
		cout << mode[0] << '\n';
	else
		cout << mode[1] << '\n';

	// 4. 범위
	// 배열은 정렬되어 있으므로 (N-1번째 - 0번째) 

	cout << num[N - 1] - num[0] << '\n';


	return 0;
}