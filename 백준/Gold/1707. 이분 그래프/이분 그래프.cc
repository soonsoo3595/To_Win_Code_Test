#include <bits/stdc++.h>

using namespace std;

int K;
int V, E;
vector<int> graph[20004];
int color[20004];

// 0 : None(Visit X)
// 1 : RED
// 2 : BLUE

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node])
        {
            if (color[neighbor] == 0)
            {
                q.push(neighbor);

                if (color[node] == 1)
                {
                    color[neighbor] = 2;
                }
                else if(color[node] == 2)
                {
                    color[neighbor] = 1;
                }
            }
        }
    }
}

bool Check()
{
    for (int i = 1; i <= V; i++)
    {
        for (int neighbor : graph[i])
        {
            if (color[i] == color[neighbor])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    cin >> K;

    while (K--)
    {
        cin >> V >> E;

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= V; i++)
        {
            // 방문하지 않은 정점만 BFS
            if (color[i] == 0)
            {
                BFS(i);
            }
        }

        if (Check())
            cout << "YES\n";
        else
            cout << "NO\n";

        memset(graph, 0, sizeof(graph));
        memset(color, 0, sizeof(color));
    }
    return 0;
}
