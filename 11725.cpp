#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v[100004];
int visited[100004];

void DFS(int parent, int child)
{
    visited[child] = parent;

    for (int connect : v[child])
    {
        if (visited[connect] != 0) continue;

        DFS(child, connect);
    }
}

int main()
{
    cin >> N;

    for (int i = 1; i < N; i++)
    {
        int A, B;
        cin >> A >> B;

        v[A].push_back(B);
        v[B].push_back(A);
    }

    visited[1] = -1;

    for (int child : v[1])
    {
        DFS(1, child);
    }

    for (int i = 2; i <= N; i++)
    {
        cout << visited[i] << '\n';
    }

    return 0;
}

