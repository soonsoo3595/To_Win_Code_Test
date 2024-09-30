#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[100004];
int psum[100004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        int input;
        cin >> input;
        arr[i] = input;
    }

    psum[1] = arr[1];

    for (int i = 2; i <= N; i++)
    {
        psum[i] = psum[i - 1] + arr[i];
    }

    while (M--)
    {
        int i, j;
        cin >> i >> j;

        cout << psum[j] - psum[i - 1] << '\n';
    }

    return 0;
}

