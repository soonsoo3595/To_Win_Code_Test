#include <bits/stdc++.h>

using namespace std;

int N, M;
int A, B;
long long cost[1004];
vector<pair<int, int>> path[1004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        path[a].push_back({ b, c });
    }

    cin >> A >> B;

    fill(cost, cost + 1004, INT_MAX);
    cost[A] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({ 0, A });

    while (!pq.empty())
    {
        int curPos = pq.top().second;
        long long curCost = pq.top().first;
        pq.pop();

        if (curCost > cost[curPos]) continue;

        for (int i = 0; i < path[curPos].size(); i++)
        {
            int nextPos = path[curPos][i].first;
            long long nextCost = curCost + path[curPos][i].second;

            if (nextCost < cost[nextPos])
            {
                cost[nextPos] = nextCost;
                pq.push({ nextCost, nextPos });
            }
        }
    }

    cout << cost[B];

    return 0;
}

