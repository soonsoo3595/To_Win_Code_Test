#include <bits/stdc++.h>

using namespace std;

int N;
char arr[30][30];
bool visited[30][30];
vector<int> answer;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int Go(int y, int x)
{
    visited[y][x] = true;

    int count = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N)   continue;
        if (visited[ny][nx] || arr[ny][nx] == '0') continue;
        count += Go(ny, nx);
    }

    return count;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = input[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] || arr[i][j] == '0')  continue;
            int count = Go(i, j);
            answer.push_back(count);
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';

    for (int num : answer)
    {
        cout << num << '\n';
    }

    return 0;
}

