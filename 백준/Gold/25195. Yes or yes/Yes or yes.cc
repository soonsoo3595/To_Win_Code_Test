#include <bits/stdc++.h>
using namespace std;

int N, M, S;
vector<int> adj[100004];
int visited[100004];

void DFS(int node)
{
    visited[node] = 1;

    for (int next : adj[node])
    {
        if (visited[next] != 0) continue;
        DFS(next);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cin >> S;

    for (int i = 0; i < S; i++)
    {
        int s;
        cin >> s;
        visited[s] = 2;
    }

    if (visited[1] == 0) DFS(1);

    bool flag = true;

    for (int i = 1; i <= N; i++)
    {
        if (adj[i].empty() && visited[i] == 1)
        {
            flag = false;
        }
    }

    if (flag)
        cout << "Yes";
    else
        cout << "yes";

    return 0;
}