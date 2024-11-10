#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main()
{

	int n;
	cin >> n;

	int count = 0;

	while (n > 0)
	{
		if (n == 1)
		{
			count = -1;
			break;
		}

		if (n % 5 != 0)
			n -= 2;
		else
			n -= 5;

		count++;
	}

	cout << count << endl;

	return 0;
}