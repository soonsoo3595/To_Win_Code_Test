#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    cin >> N;

    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < N; i++)
    {
        int count; cin >> count;
        pq.push(count);
    }

    int sum = 0;

    while (pq.size() > 1)
    {
        int A = pq.top(); pq.pop();
        int B = pq.top(); pq.pop();

        sum += (A + B);
        pq.push(A + B);
    }

    cout << sum;

    return 0;
}
 