#include <bits/stdc++.h>

using namespace std;

/*
	�迭�� �̸� = �ּҰ�
	-> Array To Pointer Decay

	int a[N]
	int* c = a
	
	vector�� �ȵ�, ���� �迭��!
*/

int main()
{
	int a[3] = { 1, 2, 3 };
	int* c = a;

	cout << c << "\n";
	cout << &a[0] << "\n";
	cout << c + 1 << "\n";
	cout << &a[1] << "\n";

}