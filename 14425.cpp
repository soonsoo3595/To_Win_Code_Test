#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, int> m;
int answer;

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }

    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        if (m[s] > 0)
            answer++;
    }

    cout << answer;

    return 0;
}

