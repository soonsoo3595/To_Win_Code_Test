#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    priority_queue<int> pq;

    while (N--)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }

    return 0;
}

