#include <bits/stdc++.h>

using namespace std;

int N, K;
bool visited[200004];

int main()
{
    cin >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, N });
    visited[N] = true;

    while (!pq.empty())
    {
        int curSecond = pq.top().first;
        int curPos = pq.top().second;
        pq.pop();

        if (curPos == K)
        {
            cout << curSecond;
            break;
        }

        int nextPos = curPos * 2;
        if (curPos <= K && !visited[nextPos])
        {
            pq.push({ curSecond, nextPos });
            visited[nextPos] = true;
        }

        nextPos = curPos - 1;
        if (nextPos >= 0 && !visited[nextPos])
        {
            pq.push({ curSecond + 1, nextPos });
            visited[nextPos] = true;
        }

        nextPos = curPos + 1;
        if (curPos <= K && !visited[nextPos])
        {
            pq.push({ curSecond + 1, nextPos });
            visited[nextPos] = true;
        }

    }

    return 0;
}

