#include <bits/stdc++.h>

using namespace std;

int N;
int top[500004];
stack<int> s;

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> top[i];
    }

    for (int i = 1; i <= N; i++)
    {
        while (!s.empty() && top[s.top()] < top[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            cout << 0 << ' ';
        }
        else
        {
            cout << s.top() << ' ';
        }

        s.push(i);
    }

    return 0;
}
