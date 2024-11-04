#include <bits/stdc++.h>
using namespace std;

int n, m;
int A, B;
int x, y;

vector<int> tree[104];
int visited[104];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    cin >> A >> B;

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    queue<int> q;
    q.push(A);

    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        
        for (int there : tree[here])
        {
            if (visited[there]) continue;

            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }

    if (visited[B] == 0)
        cout << -1;
    else
        cout << visited[B];

    return 0;
}