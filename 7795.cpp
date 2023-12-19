#include <bits/stdc++.h>

using namespace std;

int T, N, M;

int main()
{
    cin >> T;

    while (T--)
    {
        vector<int> A, B;
        
        cin >> N >> M;

        int input;
        int cnt = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> input;   A.push_back(input);
        }

        for (int i = 0; i < M; i++)
        {
            cin >> input;   B.push_back(input);
        }

        sort(B.begin(), B.end());

        for (int i = 0; i < N; i++)
        {
            auto it = lower_bound(B.begin(), B.end(), A[i]);

            cnt += (it - B.begin());
        }

        cout << cnt << '\n';
    }
    return 0;
}

