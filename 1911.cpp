#include <bits/stdc++.h>

using namespace std;

int N, L;
vector<pair<int, int>> v;

int main()
{
    cin >> N >> L;

    int nul = 0;
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        int l, r;
        cin >> l >> r;

        v.push_back({ l, r });
        
    }
    
    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        nul = max(nul, v[i].first);

        while (nul < v[i].second)
        {
            nul += L;
            answer++;
        }
    }


    cout << answer;

    return 0;
}

 