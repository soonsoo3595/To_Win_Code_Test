#include <bits/stdc++.h>
using namespace std;

int N;

void Input()
{
	cin >> N;
}

void Hanoi(int count, int from, int by, int to)
{
	if (count == 1)
	{
		cout << from << ' ' << to << '\n';
		return;
	}

	Hanoi(count - 1, from, to, by);		// N - 1개를 from->by로
	cout << from << ' ' << to << '\n';	// 가장 큰 원반을 from -> to
	Hanoi(count - 1, by, from, to);		// N - 1개를 by -> to로
}

string Add(const string& a, const string& b) {
	string result;
	int carry = 0;
	int i = a.size() - 1;
	int j = b.size() - 1;

	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;
		if (i >= 0) sum += a[i--] - '0';
		if (j >= 0) sum += b[j--] - '0';
		result.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	reverse(result.begin(), result.end());
	return result;
}

string Multiply(const string& num, int multiplier) {
	string result;
	int carry = 0;

	for (int i = num.size() - 1; i >= 0; i--) {
		int product = (num[i] - '0') * multiplier + carry;
		result.push_back(product % 10 + '0');
		carry = product / 10;
	}

	while (carry) {
		result.push_back(carry % 10 + '0');
		carry /= 10;
	}

	reverse(result.begin(), result.end());
	return result;
}

string SubtractOne(const string& num) {
	string result = num;
	int i = result.size() - 1;

	while (i >= 0) {
		if (result[i] > '0') {
			result[i]--;
			break;
		}
		else {
			result[i] = '9';
			i--;
		}
	}

	// 선행 0 제거
	if (result[0] == '0') result.erase(0, result.find_first_not_of('0'));
	return result.empty() ? "0" : result;
}

void Solve()
{
	string K = "1";
	for (int i = 0; i < N; i++)
	{
		K = Multiply(K, 2);
	}

	K = SubtractOne(K);
	cout << K << '\n';

	if (N <= 20)
	{
		Hanoi(N, 1, 2, 3);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	Solve();

	return 0;
}