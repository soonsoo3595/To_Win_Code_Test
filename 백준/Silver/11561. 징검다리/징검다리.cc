#include <bits/stdc++.h>
using namespace std;

int T;
unsigned long long N, answer;

int main()
{
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        cin >> N;

        answer = floor((sqrt(1 + 4 * 2 * N) - 1) / 2);
        
        cout << answer << '\n';
    }
}