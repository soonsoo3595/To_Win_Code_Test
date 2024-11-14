#include <bits/stdc++.h>
using namespace std;

int N, K;
vector <long long> v;

int main() 
{
    cin >> N >> K;

    v.resize(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<long long> distance;
    
    int prev = v[0];

    for (int i = 1; i < N; i++)
    {
        int dist = v[i] - prev;
        prev = v[i];
        distance.push_back(dist);
    }

    sort(distance.begin(), distance.end(), greater<long long>());

    long long answer = 0;

    for (int i = K - 1; i < N - 1; i++)
    {
        answer += distance[i];
    }

    cout << answer;

    return 0;
}

// 1 3 6 6 7 9
// 