#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int> pq;
vector<int> v;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        pq.push(input);
    }

    for (int i = 0; i < n; i++)
    {
        v.push_back(pq.top()); pq.pop();
    }

    reverse(v.begin(), v.end());

    int x;
    cin >> x;

    int left = 0; int right = n - 1;

    int ret = 0;

    while (true)
    {
        if (left >= right) break;

        if (v[left] + v[right] == x)
        {
            ret++;
            left++; right--;
        }
        else if (v[left] + v[right] < x)
        {
            left++;
        }
        else if (v[left] + v[right] > x)
        {
            right--;
        }
    }
    
    cout << ret;

    return 0;
}

