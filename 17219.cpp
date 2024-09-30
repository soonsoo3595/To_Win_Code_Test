#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, string> m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> N >> M;
	while (N--)
	{
		string key, value;
		cin >> key >> value;
		m[key] = value;
	}

	while (M--)
	{
		string key;
		cin >> key;
		cout << m[key] << '\n';
	}

    return 0;
}

