#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000004;
int n, m;
int parent[MAX];
int level[MAX];

int Find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    int rX = Find(x);
    int rY = Find(y);

    if (rX != rY)
    {
        if (level[rX] > level[rY])
        {
            parent[rY] = rX;
        }
        else if (level[rX] < level[rY])
        {
            parent[rX] = rY;
        }
        else
        {
            parent[rY] = rX;
            level[rX]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    while (m--)
    {
        int opt, a, b;
        cin >> opt >> a >> b;

        if (opt == 0)
        {
            if (a == b)
                continue;

            Union(a, b);
        }
        else
        {
            if (a == b)
            {
                cout << "YES\n";
                continue;
            }

            if (Find(a) == Find(b))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}

