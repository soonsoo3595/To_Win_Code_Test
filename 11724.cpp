#include <bits/stdc++.h>

using namespace std;

int N, M;
bool visited[1004];
vector<int> adj[1004];
int answer;

bool DFS(int here)
{
    if (visited[here]) return false;
    visited[here] = true;

    for (int there : adj[here])
    {
        DFS(there);
    }

    return true;
}

int main()
{
    cin >> N >> M;

    while (M--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        if (DFS(i)) answer++;
    }

    cout << answer;

    return 0;
}

