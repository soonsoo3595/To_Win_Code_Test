#include <bits/stdc++.h>

using namespace std;

int T, N, M;

int func(int target, vector<int> &v)
{
    int left = 0; int right = v.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (target > v[mid])
            left = mid + 1;
        else if (target < v[mid])
            right = mid - 1;
        else
            return 1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        cin >> N;
        
        vector<int> v;
        int input;

        for (int i = 0; i < N; i++)
        {
            cin >> input;
            v.push_back(input);
        }

        sort(v.begin(), v.end());

        cin >> M;

        for (int i = 0; i < M; i++)
        {
            cin >> input;
            cout << func(input, v) << '\n';
        }
    }
    return 0;
}

