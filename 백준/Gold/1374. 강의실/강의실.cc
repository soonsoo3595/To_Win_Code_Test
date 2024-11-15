#include <bits/stdc++.h>
using namespace std;

int N;
struct Lecture
{
    int id;
    int start;
    int end;
};
vector<Lecture> lectures;

bool Compare(Lecture& l1, Lecture& l2)
{
    return l1.start < l2.start;
}

void Input()
{
    cin >> N;

}

void Solve()
{
    lectures.resize(N);

    for (int i = 0; i < N; i++)
    {
        int id, start, end;
        cin >> id >> start >> end;
        lectures[i] = { id, start, end };
    }

    sort(lectures.begin(), lectures.end(), Compare);

    priority_queue<int, vector<int>, greater<>> pq;
    pq.push(lectures[0].end);

    // pq의 size는 강의실의 개수와 같다

    for (int i = 1; i < N; i++)
    {
        // 가장 빨리 끝나는 강의의 끝나는 시간(pq)보다 현재 강의의 시작시간이 같거나 뒤이면 top을 빼고 현재 강의 push
        if (pq.top() <= lectures[i].start)
        {
            pq.pop();
            pq.push(lectures[i].end);
        }
        // 더 일찍 시작하면 그냥 push
        else
        {
            pq.push(lectures[i].end);
        }
    }

    cout << pq.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    Solve();

    return 0;
}

// 2 14
// 3 8
// 6 20
// 6 27
// 7 13
// 12 18
// 15 21
// 20 25