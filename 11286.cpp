#include <bits/stdc++.h>

using namespace std;

int N;

struct cmp
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
        {
            return a > b;
        }
        
        return abs(a) > abs(b);
    }
};

int main()
{
    cin >> N;

    priority_queue<int, vector<int>, cmp> pq;

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

