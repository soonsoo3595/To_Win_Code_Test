#include <iostream>

using namespace std;

int d[12];

int main()
{
	int T;
	cin >> T;

	d[0] = 1;
	d[1] = 1;
	d[2] = d[0] + d[1];

	while (T--)
	{
		int n;
		cin >> n;
	
		for (int i = 3; i <= n;i++)
		{
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}

		cout << d[n] << '\n';
	}

	return 0;
}