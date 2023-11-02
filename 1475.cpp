#include <bits/stdc++.h>

using namespace std;

string N;
int arr[10];
int answer;


int main()
{
    cin >> N;

    for (int i = 0; i < N.size(); i++)
    {
		arr[N[i] - '0']++;
	}
    
    bool flag = true;

    while (true)
    {
        answer++;

        for (int i = 0; i < 10; i++)
        {
            if (i == 6)
            {
                if (arr[i])
                {
                    arr[i]--;
                }
                else if (arr[i] == 0 && arr[9])
                {
                    arr[9]--;
                }
            }
            else if (i == 9)
            {
                if (arr[i])
                {
                    arr[i]--;
                }
                else if (arr[i] == 0 && arr[6])
                {
					arr[6]--;
				}
            }
            else
            {
                if (arr[i])
                {
                    arr[i]--;
                }
            }
        }

        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0 && arr[4] == 0 && arr[5] == 0 && arr[6] == 0 && arr[7] == 0 && arr[8] == 0 && arr[9] == 0)
            break;
    }

    cout << answer;

    return 0;
}

