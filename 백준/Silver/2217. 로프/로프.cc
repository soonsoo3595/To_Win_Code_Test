#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> rope;
int answer;

void Input()
{
    cin >> N;

    rope.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> rope[i];
    }
}

void Solve()
{
    sort(rope.begin(), rope.end());

    for (int i = 0; i < rope.size(); i++)
    {
        answer = max(answer, rope[i] * (N - i));
    }

    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}
