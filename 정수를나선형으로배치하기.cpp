#include <string>
#include <vector>

using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int arr[31][31];
int visited[31][31];

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    int x = 0, y = 0;

    int idx = 0;

    for (int i = 1; i <= n * n; i++)
    {
        visited[y][x] = 1;
        arr[y][x] = i;

        int ny = y + dy[idx];
        int nx = x + dx[idx];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] == 1)
        {
            idx = (idx + 1) % 4;
            ny = y + dy[idx];
            nx = x + dx[idx];
        }

        x = nx; y = ny;
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> v;

        for (int j = 0; j < n; j++)
        {
            v.push_back(arr[i][j]);
        }

        answer.push_back(v);
    }


    return answer;
}