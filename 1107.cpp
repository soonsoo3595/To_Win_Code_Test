#include <bits/stdc++.h>

using namespace std;

int N, M;
bool buttons[10];

int main()
{
    cin >> N >> M;

    if (M == 0)
    {
        int length = to_string(N).size();
        cout << min(length, abs(N - 100));
        return 0;
    }
    else if (M == 10)
    {
        cout << abs(N - 100);
        return 0;
    }

    for (int i = 0; i < M; i++)
    {
        int button; cin >> button;
        buttons[button] = true;
    }

    int count1 = INT_MAX;

    for (int i = N; i >= 0; i--)
    {
        string channel = to_string(i);
        bool flag = true;
        for (int j = 0; j < channel.size(); j++)
        {
            if (buttons[channel[j] - '0'])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            count1 = channel.size();
            count1 += abs(N - i);
            break;
        }
    }

    int count2 = INT_MAX;
    for (int i = N; i <= 1000000; i++)
    {
        string channel = to_string(i);
        bool flag = true;
        for (int j = 0; j < channel.size(); j++)
        {
            if (buttons[channel[j] - '0'])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            count2 = channel.size();
            count2 += abs(N - i);
            break;
        }
    }

    int count3 = abs(N - 100);

    cout << min(count1, min(count2, count3));

    return 0;
}

