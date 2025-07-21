#include <iostream>
using namespace std;

int main() {

	int N; // 색종이의 개수
	int arr[100][100] = { 0, };
	int a, b;

	cin >> N;

	while (N--) {
		cin >> a >> b;
		for (int i = b; i < b + 10; i++) {
			for (int j = a; j < a + 10; j++) {
				if (arr[i][j] == 0)
					arr[i][j]++;
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1)
				sum++;
		}
	}

	cout << sum;
}