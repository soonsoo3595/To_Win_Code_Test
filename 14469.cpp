#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> v;
priority_queue<int, vector<int>> pq;
int answer;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({ a, b });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        if (answer < v[i].first) answer = v[i].first;

        answer += v[i].second;
    }

    cout << answer;

    return 0;
}

