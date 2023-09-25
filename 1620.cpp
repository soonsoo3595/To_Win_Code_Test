#include <bits/stdc++.h>

using namespace std;

int N, M;

map<int, string> dict1;
map<string, int> dict2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
	{
		string input;
		cin >> input;
		dict1[i] = input;
		dict2[input] = i;
	}

	while (M--)
	{
		string input;
		cin >> input;

		if (atoi(input.c_str()))
		{
			int num = stoi(input.c_str());
			cout << dict1[num] << '\n';
		}
		else
		{
			cout << dict2[input] << '\n';
		}
	}
}