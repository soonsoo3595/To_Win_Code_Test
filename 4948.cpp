#include <bits/stdc++.h>

using namespace std;

const int MAX = 123456;
int n;
bool arr[2 * MAX + 4];

void Func()
{
    arr[0] = arr[1] = true;

    for (int i = 2; i <= 2 * MAX; i++)
    {
        if (arr[i] == false)
        {
            for (int j = i * 2; j <= 2 * MAX; j += i)
            {
				arr[j] = true;
			}
		}
	}
}

int main()
{
    Func();

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        int answer = 0;

        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (arr[i] == false)
            {
                cout << i << ' ';
                answer++;
            }
        }
        
        cout << answer << "\n";
    }



    return 0;
}

