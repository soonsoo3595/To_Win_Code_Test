#include <bits/stdc++.h>

using namespace std;

vector<string> entry;
vector<char> ret;
int N;
int arr[26];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		entry.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		arr[entry[i][0] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] >= 5)
		{
			ret.push_back((char)(i + 'a'));
		}
	}

	sort(ret.begin(), ret.end());

	if (ret.size() == 0)
	{
		cout << "PREDAJA" << '\n';
	}
	else
	{
		for (char c : ret)
			cout << c;
	}

	return 0;
}