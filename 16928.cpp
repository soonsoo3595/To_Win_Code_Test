#include <bits/stdc++.h>

using namespace std;

int N, M;
bool visited[104];
vector<pair<int, int>> v;
vector<pair<int, int>> snake;

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({ a, b });
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        snake.push_back({ a, b });
    }

    visited[1] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, 1 });

    while (!pq.empty())
    {
        int curCount = pq.top().first;
        int curPos = pq.top().second;
        pq.pop();

        cout << curPos << " : " << curCount << '\n';

        if (curPos == 100)
        {
            cout << curCount;
            break;
        }

        for (int i = 1; i <= 6; i++)
        {
            bool flag = false;
            int nextPos = curPos + i;

            if (nextPos > 100 || visited[nextPos]) continue;
            visited[nextPos] = true;

            // 사다리 확인
            for (int j = 0; j < v.size(); j++)
            {
                if (nextPos == v[j].first)
                {
                    pq.push({ curCount + 1, v[j].second });
                    visited[v[j].second] = true;
                    flag = true;
                    break;
                }
            }

            for (int j = 0; j < snake.size(); j++)
            {
                if (nextPos == snake[j].first)
                {
                    visited[snake[j].second] = true;
                    pq.push({curCount + 1, snake[j].second});
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                pq.push({ curCount + 1, nextPos });
            }
        }
    }

    return 0;
}

