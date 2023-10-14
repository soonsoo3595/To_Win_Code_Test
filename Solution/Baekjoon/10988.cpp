#include <bits/stdc++.h>

using namespace std;

string word;

int main()
{
	cin >> word;

	string reverseWord = word;

	reverse(reverseWord.begin(), reverseWord.end());

	if (word == reverseWord)
		cout << 1;
	else
		cout << 0;

	return 0;
}