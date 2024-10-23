#include <bits/stdc++.h>

using namespace std;

int N;
int S, B;
vector<pair<int, int>> v;
int answer = INT_MAX;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> S >> B;
        v.push_back({ S, B });
    }

    for (int i = 1; i < (1 << N); i++)
    {
        int sour = 1;
        int bitter = 0;

        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                sour *= v[j].first;
                bitter += v[j].second;
            }
        }

        int diff = abs(sour - bitter);
        answer = min(answer, diff);
    }

    cout << answer;

    return 0;
}
