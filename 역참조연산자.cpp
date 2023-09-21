#include <bits/stdc++.h>

using namespace std;

int main()
{
	// 주소값 앞에 *를 붙이면 주소가 가리키는 값을 볼 수 있다
	string a = "kundol";
	string* b = &a;
	cout << b << '\n';
	cout << *b << '\n';

}