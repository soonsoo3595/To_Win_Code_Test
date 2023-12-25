#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[104];
int visited[104];
int answer;

void DFS(int here)
{
    answer++;
    visited[here] = 1;

    for (int there : adj[here])
    {
        if (visited[there])  continue;

        DFS(there);
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(1);

    cout << answer - 1;

    return 0;
}

