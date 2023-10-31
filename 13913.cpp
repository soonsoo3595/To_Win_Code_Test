#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;
int N, K;

int visited[MAX + 4];
int before[MAX + 4];

int main()
{
    cin >> N >> K;

    if (N == K)
    {
        cout << 0 << '\n' << N;
        return 0;
    }

    queue<int> q;
    q.push(N);
    visited[N] = 1;
    before[N] = -1;

    while (q.size())
    {
        int here = q.front(); q.pop();

        for (int next : {here - 1, here + 1, here * 2})
        {
            if (next < 0 || next > MAX) continue;
            if (visited[next]) continue;
            
            visited[next] = visited[here] + 1;
            before[next] = here;
            q.push(next);
        }
        
    }

    stack<int> s;
    int target = K;

    while (true)
    {
        if (target == -1)
        {
            break;
        }

        s.push(target);
        target = before[target];
    }


    cout << visited[K] - 1 << '\n';

    while (s.size())
    {
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}

