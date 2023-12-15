#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
vector<int> op;

int answer_max = INT_MIN;
int answer_min = INT_MAX;

int main()
{
    cin >> N;
    
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        v.push_back(input);
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> input;

        for (int j = 0; j < input; j++)
        {
            op.push_back(i);
        }
    }

    sort(op.begin(), op.end());

    do
    {
        int sum = v[0];

        for (int i = 0; i < op.size(); i++)
        {
            int a = v[i + 1];

            switch (op[i])
            {
            case 0:
                sum = sum + a;
                break;
            case 1:
                sum = sum - a;
                break;
            case 2:
                sum = sum * a;
                break;
            case 3:
                sum = sum / a;
                break;
            }

        }

        if (sum > answer_max)
            answer_max = sum;

        if (sum < answer_min)
            answer_min = sum;

    }while (next_permutation(op.begin(), op.end()));
   
    cout << answer_max << '\n' << answer_min;


    return 0;
}

