#include <bits/stdc++.h>

using namespace std;

// 叔鳶推ににににににににににににににに

int N;
int first, last;
vector<string> v;
string pattern, filename;

vector<string> split(string str, string delimeter)
{
	vector<string> ret;
	long long pos = 0;
	string token = "";
	
	while ((pos = str.find(delimeter)) != string::npos)
	{
		token = str.substr(0, pos);
		ret.push_back(token);
		str.erase(0, pos + delimeter.length());
	}
	ret.push_back(str);

	return ret;
}

int main()
{
	cin >> N;
	cin >> pattern;
	
	v = split(pattern, "*");

	while (N--)
	{
		cin >> filename;

		bool flag = true;

		for (int i = 0; i < v[0].size(); i++)
		{
			if (filename[i] != v[0][i])
			{
				flag = false;
				break;
			}
		}

		auto it = filename.rbegin();
		auto it2 = v[1].rbegin();

		for (int i = 0; i < v[1].size(); i++)
		{
			if (*(it++) != *(it2++))
			{
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "DA";
		else
			cout << "NE";

		cout << '\n';
	}
}