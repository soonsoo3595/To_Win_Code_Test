#include <bits/stdc++.h>

using namespace std;

int N, M;

int T;
int answer = 0;

struct Bucket
{
    int left;
    int right;

    void Move(int dist)
    {
        left += dist;
        right += dist;
    }
};

int main()
{
    cin >> N >> M;
    cin >> T;

    Bucket bucket;
    bucket.left = 1;
    bucket.right = M;

    while (T--)
    {
        int pos;
        cin >> pos;

        int move = 0;

        // 사과가 떨어지는 곳이 바구니의 왼쪽에 있으면
        if (pos < bucket.left)
        {
            move = bucket.left - pos;
            answer += move;
            bucket.Move(-move);
        }
        // 사과가 떨어지는 곳이 바구니 위치에 포함(안적어도 됨)
        else if (pos > bucket.left && pos < bucket.right)
        {
            move = 0;
            answer += move;
        }
        // 사과가 떨어지는 곳이 바구니의 오른쪽에 있으면
        else if (pos > bucket.right)
        {
            move = pos - bucket.right;
            answer += move;
            bucket.Move(move);
        }
    }
    
    cout << answer;

    return 0;
}

