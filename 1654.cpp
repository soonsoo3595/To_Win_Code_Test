#include <bits/stdc++.h>

using namespace std;

int K, N;
vector<long long> v;
long long answer = 0;

int func(long long mid)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        count += (v[i] / mid);
    }

    return count;
}

int main()
{
    cin >> K >> N;

    long long left = 0, right = 0;

    while (K--)
    {
        long long input;
        cin >> input;
        right = max(right ,input);
        v.push_back(input);
    }

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        
        if(mid == 0) mid = 1;

        if (func(mid) < N)
        {
            right = mid - 1;
        }
        else
        {
            answer = max(mid, answer);
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}

