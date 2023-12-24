#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin >> N;

    int input;

    for (int i = 0; i < N; i++)
    {
        cin >> input;

        if (input == 0)
        {
            if (pq.size())
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else
        {
            pq.push(input);
        }
    }



    return 0;
}

