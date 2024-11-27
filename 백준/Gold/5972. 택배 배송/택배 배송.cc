#include <bits/stdc++.h>
using namespace std;

int N, M;

constexpr int MAX = 987654321;

vector<pair<int, int>> adj[50004];
int dist[50004];

void Input()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }
}

void Solve()
{
    fill(dist, dist + N + 1, MAX);

    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, 1 });

    while (!pq.empty())
    {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curCost > dist[curNode]) continue;

        for (auto& path : adj[curNode])
        {
            int nextCost = curCost + path.second;
            int nextNode = path.first;

            if (nextCost < dist[nextNode])
            {
                dist[nextNode] = nextCost;
                pq.push({ nextCost, nextNode });
            }
        }
    }

    cout << dist[N];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}
