#include <bits/stdc++.h>

using namespace std;

int N, M, K, X;
vector<int> graph[300004];
int dist[300004];

int main()
{
    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    fill(dist, dist + 300004, INT_MAX);
    dist[X] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, X });

    while (!pq.empty())
    {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        
        for (int next : graph[curNode])
        {
            int nextDist = curDist + 1;
            
            if (nextDist < dist[next])
            {
                dist[next] = nextDist;
                pq.push({ nextDist, next });
            }
        }
    }

    bool flag = false;

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == K)
        {
            cout << i << '\n';
            flag = true;
        }
    }

    if (!flag)
        cout << "-1";

    return 0;
}

