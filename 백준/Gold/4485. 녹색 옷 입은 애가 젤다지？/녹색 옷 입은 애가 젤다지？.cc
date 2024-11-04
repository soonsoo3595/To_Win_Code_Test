#include <bits/stdc++.h>
using namespace std;

int N;
int arr[126][126];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int index = 1;

    while (true)
    {
        cin >> N;

        if (N == 0)
            break;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> arr[i][j];
            }
        }

        vector<vector<int>> dist(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++) 
        {
            fill(dist[i].begin(), dist[i].end(), INT_MAX);
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({ arr[0][0], {0, 0} });
        dist[0][0] = arr[0][0];

        while (!pq.empty())
        {
            int y = pq.top().second.first;
            int x = pq.top().second.second;
            int curDist = pq.top().first;
            pq.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

                int nextDist = curDist + arr[ny][nx];
                if (nextDist < dist[ny][nx])
                {
                    dist[ny][nx] = nextDist;
                    pq.push({ nextDist, { ny, nx } });
                }
            }
        }

        cout << "Problem " << index++ << ": " << dist[N - 1][N - 1] << '\n';
    }


    return 0;
}