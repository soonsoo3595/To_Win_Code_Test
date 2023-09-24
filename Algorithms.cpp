#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
	int a, b, c;
	
	pair<int, int> pr = { 1, 2 };
	tuple<int, int, int> tp = make_tuple(5, 7, 8);

	tie(a, b, c) = tp;

	cout << a << b << c;
}