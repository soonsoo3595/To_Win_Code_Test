#include <bits/stdc++.h>

using namespace std;

int N, M, R;
vector<int> adj[100004];
int visited[100004];
int order = 1;

void DFS(int here)
{
    visited[here] = order++;

    for (int there : adj[here])
    {
        if (visited[there]) continue;

        DFS(there);
    }
}

int main()
{
    cin >> N >> M >> R;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    DFS(R);

    for (int i = 1; i <= N; i++)
    {
        cout << visited[i] << '\n';
    }

    return 0;
}
 