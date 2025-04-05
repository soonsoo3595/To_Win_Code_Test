#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[504];
bool visited[504];
int answer;

void Input()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void Solve()
{
    queue<pair<int, int>> q;
    q.push({1, 0});

    while (!q.empty())
    {
        int num = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (visited[num] || depth > 2)
            continue;

        visited[num] = true;
        answer++;

        for (int next : adj[num])
        {
            if (visited[next] == false)
            {
                q.push({next, depth + 1});
            }
        }
    }

    cout << answer - 1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Solve();

    return 0;
}