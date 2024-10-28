#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[104];
int visited[104];

void DFS(int here)
{
    for (int there : adj[here])
    {
        if (visited[there]) continue;
        visited[there] = 1;
        DFS(there);
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input;
            cin >> input;

            if (input == 1)
            {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        DFS(i);

        for (int j = 0; j < N; j++)
        {
            cout << visited[j] << ' ';
        }

        memset(visited, 0, sizeof(visited));
        cout << '\n';
    }

    return 0;
}
