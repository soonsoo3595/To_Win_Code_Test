// 叔鳶推にににににににに

#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> v;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	auto it = v.begin();

	while (it != v.end())
	{
		int sum = 0;


		answer.push_back(sum);
		it++;
	}

	sort(answer.begin(), answer.end());
	
	cout << *(answer.end() - 1);

}