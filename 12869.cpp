#include <bits/stdc++.h>

using namespace std;

int N;
int damage[] = { 9, 3, 1 };
int answer;

void Attack(vector<int>& scv)
{
	for (int i = 0; i < scv.size(); i++)
	{
		scv[i] -= damage[i];
		if (scv[i] < 0) scv[i] = 0;
	}

}

void Func(vector<int> scv, int cnt)
{
	if (scv[0] == 0 && scv[1] == 0 && scv[2] == 0)
	{
		cout << cnt << '\n';
		return;
	}

	cout << scv[0] << " " << scv[1] << " " << scv[2] << "일 때 ->";
	Attack(scv);
	cnt++;
	cout << scv[0] << " " << scv[1] << " " << scv[2] << "\n";

	// sort(scv.begin(), scv.end());

	do
	{
		Func(scv, cnt + 1);
	} while (next_permutation(scv.begin(), scv.end()));

}

int main()
{
    cin >> N;

	vector<int> v;

    for (int i = 0; i < N; i++)
    {
		int input;
		cin >> input;

		v.push_back(input);
	}

	sort(v.begin(), v.end());

	do
	{
		cout << "시작\n";
		Func(v, 0);
	} while (next_permutation(v.begin(), v.end()));


    return 0;
}

