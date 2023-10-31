#include <bits/stdc++.h>

using namespace std;

const int MAX = 500000;
int N, K;

int visited[MAX + 4];
int answer = -1;

int add(int n)
{
    return n * (n + 1) / 2;
}

int main()
{
    cin >> N >> K;

    if (N == K)
    {
        cout << 0;
        return 0;
    }

    queue<int> q;
    q.push(N);
    visited[N] = 1;
    int nk = K;

    while (q.size())
    {
        int here = q.front(); q.pop();

        for (int next : {here - 1, here + 1, here * 2})
        {
            nk = K + add(visited[here]);

            if (next < 0 || next > MAX || next == here) continue;
            if (here > nk && next != here - 1) continue;
            if (nk > MAX) continue;

            cout << here << " : " << next << " : " << nk << '\n';
            if (next == nk)
            {
                cout << visited[here] << '\n';
                return 0;
            }

            // if (next != here - 1 && here > K + add(visited[here] - 1)) continue;
            // if (visited[next]) continue;

            visited[next] = visited[here] + 1;
            q.push(next);
        }
    }
    
    cout << -1;

    return 0;
}

