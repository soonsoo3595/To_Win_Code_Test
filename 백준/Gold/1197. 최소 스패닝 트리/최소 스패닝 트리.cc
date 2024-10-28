#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, weight;
};

int V, E;
vector<Edge> edges;
vector<Edge> MST;

int parent[10004];
int level[10004];
int answer;

bool Compare(Edge& e1, Edge& e2)
{
    return e1.weight < e2.weight;
}

int Find(int u)
{
    if (u == parent[u]) return u;

    return parent[u] = Find(parent[u]);
}

void Union(int u, int v)
{
    u = Find(u);
    v = Find(v);

    if (u != v)
    {
        if (level[u] > level[v])
        {
            parent[v] = u;
        }
        else if (level[u] < level[v])
        {
            parent[u] = v;
        }
        else
        {
            parent[v] = u;
            level[u]++;
        }
    }
}

int main()
{
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;

        edges.push_back({ u, v, weight });
    }

    sort(edges.begin(), edges.end(), Compare);

    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

    for (auto& edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        if (Find(u) != Find(v))
        {
            Union(u, v);
            
            answer += weight;
        }
    }

    cout << answer;

    return 0;
}
