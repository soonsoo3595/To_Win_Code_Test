#include <bits/stdc++.h>

using namespace std;

int N;
int arr[51][51];
int cnt[51];
int root;
int answer;

void Func(int node)
{
    if (!cnt[node])
    {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[node][i] == 1)
            Func(i);
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int idx;
        cin >> idx;

        if (idx == -1)
        {
            root = i;
            continue;
        }
       
        arr[idx][i] = 1;
        cnt[idx]++;
    }

    int del_node = 0;
    cin >> del_node;

    // 삭제할 노드를 찾아 삭제해야함
    for (int i = 0; i < N; i++)
    {
        if (arr[i][del_node] == 1)
        {
            arr[i][del_node] = 0;
            cnt[i]--;
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[del_node][i] == 1)
        {
            arr[del_node][i] = 0;
            cnt[del_node]--;
        }
    }

    if (root == del_node)
        answer = 0;
    else
       Func(root);

    cout << answer;

    return 0;
}

