#include <bits/stdc++.h>

using namespace std;

int N, M;
map<int, int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        m[input]++;
    }
    
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int input;
        cin >> input;
        
        cout << m[input] << ' ';
    }

    return 0;
}

