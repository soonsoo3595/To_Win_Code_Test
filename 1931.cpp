#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> v;

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

    int start = v[0].first, end = v[0].second;
    int answer = 1;

    for (int i = 1; i < N; i++)
    {
        if (start < v[i].first && end > v[i].second) 
        {
            start = v[i].first; end = v[i].second;
        }
        else if (v[i].first >= end)
        {
            start = v[i].first; end = v[i].second;
            answer++;
        }
    }

    cout << answer;

    return 0;
}

