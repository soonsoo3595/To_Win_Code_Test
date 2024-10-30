#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[51];
int visited[51];
int min_score = INT_MAX;
vector<int> master;

void BFS(int num)
{
    queue<int> q;
    q.push(num);
    visited[num] = 1;

    int score = 0;

    while (!q.empty())
    {
        int member = q.front();
        q.pop();

        for (int my_friend : adj[member])
        {
            if (visited[my_friend] != 0)
                continue;

            visited[my_friend] = visited[member] + 1;
            q.push(my_friend);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        score = max(score, visited[i]);
    }

    if (score < min_score)
    {
        master.clear();
        min_score = score;
        master.push_back(num);
    }
    else if (score == min_score)
    {
        master.push_back(num);
    }
}

int main()
{
    cin >> N;

    while (true)
    {
        int A, B;
        cin >> A >> B;

        if (A == -1 && B == -1)
            break;

        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    for (int i = 1; i <= N; i++)
    {
        BFS(i);
        memset(visited, 0, sizeof(visited));
    }

    cout << min_score - 1 << ' ' << master.size() << '\n';
    sort(master.begin(), master.end());

    for (int member : master)
    {
        cout << member << ' ';
    }

    return 0;
}
