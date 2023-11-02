#include <bits/stdc++.h>

using namespace std;

int N, K;

int visited[100004];

void Go(int here)
{
    queue<int> q;
    q.push(here);
    cout << here << "->";
    visited[here] = 1;

    if (here == K)
        return;

    while (q.size())
    {
        here = q.front(); q.pop();

        
    }
    if(here - 1 >= 0 && !visited[here - 1])
        Go(here - 1);
    if(here + 1 <= 100000 && here <= N && !visited[here + 1])
		Go(here + 1);
    if(here * 2 <= 100000 && here <= N &&!visited[here * 2])
        Go(here * 2);
}

int main()
{
    cin >> N >> K;


    Go(N);

    return 0;
}

