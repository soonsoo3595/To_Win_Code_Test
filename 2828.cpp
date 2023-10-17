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

        // ����� �������� ���� �ٱ����� ���ʿ� ������
        if (pos < bucket.left)
        {
            move = bucket.left - pos;
            answer += move;
            bucket.Move(-move);
        }
        // ����� �������� ���� �ٱ��� ��ġ�� ����(����� ��)
        else if (pos > bucket.left && pos < bucket.right)
        {
            move = 0;
            answer += move;
        }
        // ����� �������� ���� �ٱ����� �����ʿ� ������
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

