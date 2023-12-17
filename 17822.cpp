#include <bits/stdc++.h>

using namespace std;

int N, M, T;

vector<int> board[54];
set<pair<int, int>> s;

void Print()
{
    cout << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void Rotate(int idx, int d, int k)
{
    if (d == 0)
    {
        rotate(board[idx].begin(), board[idx].end() - k, board[idx].end());
    }
    else if (d == 1)
    {
        rotate(board[idx].begin(), board[idx].begin() + k, board[idx].end());
    }
}

double Average()
{
    int ret = 0;
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0)    continue;
            ret += board[i][j];
            count++;
        }
    }

    if (count == 0)  return 0;
    else return (double)ret / count;
}

void adjacent(int i, int j)
{
    if (board[i][j] == board[i][(j + 1) % M])               s.insert({ i, (j + 1) % M });

    if (j != 0 && board[i][j] == board[i][j - 1])           s.insert({ i, j - 1 });
    else if (j == 0 && board[i][j] == board[i][M - 1])      s.insert({ i, M - 1 });

    if (i < N - 1 && board[i][j] == board[i + 1][j])        s.insert({ i + 1, j });
    if (i > 0 && board[i][j] == board[i - 1][j])            s.insert({ i - 1, j });

}

int main()
{
    cin >> N >> M >> T;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int input; cin >> input;
            board[i].push_back(input);
        }
    }

    while (T--)
    {
        int x, d, k;
        cin >> x >> d >> k;
        
        for (int i = x; i <= N; i += x)
        {
            Rotate(i - 1, d, k);
        }
        
        bool flag = false;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == 0) continue;

                adjacent(i, j);
            }
        }

        if (s.empty())
        {
            double avg = Average();
            if (avg == 0)
                break;

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (board[i][j] == 0) continue;

                    if (board[i][j] > avg)
                        board[i][j]--;
                    else if(board[i][j] < avg)
                        board[i][j]++;
                }
            }
        }
        else
        {
            for (auto p : s)
            {
                board[p.first][p.second] = 0;
            }
        }

        s.clear();
    }

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sum += board[i][j];
        }
    }

    cout << sum;


    return 0;
}

