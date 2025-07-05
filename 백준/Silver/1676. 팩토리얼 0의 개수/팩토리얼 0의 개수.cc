#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	int count = 0;
	int num = 5;

	while (num <= N)
	{
		count += N / num;
		num *= 5;
	}

	cout << count;

}