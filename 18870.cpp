#include <bits/stdc++.h>
#include "unordered_map"
using namespace std;

int N;
vector<int> v1;
unordered_map<int, int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int input; cin >> input;
        v1.push_back(input);
    }

    vector<int> v2(v1);
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    int size = v2.size();
    for (int i = 0; i < size; i++)
    {
        m[v2[i]] = i;
    }

    for (int i = 0; i < N; i++)
    {
        cout << m[v1[i]] << ' ';
    }
    
    return 0;
}

