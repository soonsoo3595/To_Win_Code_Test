#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> v;
priority_queue<int> pq;
// 1. 숫자가 모두 C보다 작거나 같음
// 2. 등장하는 횟수가 같으면 먼저 나온 것이 앞에

int main()
{
    cin >> N >> C;

    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }


    return 0;
}

