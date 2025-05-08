#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool isgroup(string &word) {
	
	int len = word.size();
	vector<char> v;

	bool group = true;

	for (int i = 0; i < len; i++) {
		if (v.end() == find(v.begin(), v.end(), word[i])) {
			v.push_back(word[i]);
		}
		else if (word[i] != word[i - 1]) {
			group = false;
		}
	}
	
	return group;
}

int main() {
	
	int N;
	cin >> N;

	string word;

	int num = 0;

	while (N--) {
		cin >> word;

		if (isgroup(word))
			num++;
		
	}

	cout << num;
}