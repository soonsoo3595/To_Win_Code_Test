#include <bits/stdc++.h>

using namespace std;

string a;
vector<string> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a;
	
	/* next_permutaion -> 시간 에러*/
	sort(a.begin(), a.end());

	while (next_permutation(a.begin(), a.end()))
	{
		int size = a.size();
		bool flag = true;
		for (int i = 0; i < size / 2; i++)
		{
			if (a[i] != a[size - i - 1])
			{
				flag = false;
				break;
			}
		}
		
		if (flag)
			answer.push_back(a);
	}

	sort(answer.begin(), answer.end());

	if (answer.empty())
	{
		cout << "I'm Sorry Hansoo" << '\n';
	}
	else
	{
		cout << answer[0];
	}
}