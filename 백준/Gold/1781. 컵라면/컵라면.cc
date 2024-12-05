#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

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

    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i].second);
        
        if(pq.size() > v[i].first)
        {
            pq.pop();
        }
    }

    int ret = 0;

    while (pq.size())
    {
        ret += pq.top(); pq.pop();
    }

    cout << ret;

    return 0;
}

