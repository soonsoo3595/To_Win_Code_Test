#include <bits/stdc++.h>

using namespace std;

int N, M;
map<int, int> m;
int answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int input;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        m[input] = 1;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> input;
        if (m[input] == 1)
            m[input] = 0;
        else
            m[input] = 1;
    }
    
    for (auto value : m)
    {
        if (value.second == 1)
            answer++;
    }

    cout << answer;

    return 0;
}

