#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> getMergedLineSegments(vector<vector<int>>& lineSegments) {
    vector<vector<int>> answer;
    answer.push_back(lineSegments[0]);

    for (int i = 1; i < lineSegments.size(); i++)
    {
        bool flag = false;
        
        for (int j = 0; j < answer.size(); j++)
        {
            // 경우의 수를 많이 나눠봐야 함
            if (answer[j][0] > lineSegments[i][0] && answer[j][1] < lineSegments[i][1])
            {
                answer[j][0] = lineSegments[i][0];
                answer[j][1] = lineSegments[i][1];
                flag = true;
                break;
            }
            else if (answer[j][0] < lineSegments[i][0] && answer[j][1] > lineSegments[i][1])
            {
                flag = true;
                break;
            }
            else if (answer[j][0] < lineSegments[i][1] && answer[j][1] > lineSegments[i][1])
            {
                answer[j][0] = lineSegments[i][0];
                flag = true;
                break;
            }
            else if (answer[j][0] < lineSegments[i][0] && answer[j][1] > lineSegments[i][0])
            {
                answer[j][1] = lineSegments[i][1];
                flag = true;
                break;
            }
            else if (answer[j][1] == lineSegments[i][0])
            {
                answer[j][1] = lineSegments[i][1];
                flag = true;
                break;
            }
            else if (answer[j][0] == lineSegments[i][1])
            {
                answer[j][0] = lineSegments[i][0];
                flag = true;
                break;
            }
            else
            {
                continue;
            }
        }

        if (!flag)
            answer.push_back(lineSegments[i]);
    }

    return answer;
}

int main()
{
    vector<vector<int>> v;
    vector<vector<int>> v1;

    v.push_back({ 6, 9 });
    v.push_back({ 2, 3 });
    v.push_back({ 9, 11 });
    v.push_back({ 1, 5});
    v.push_back({ 14, 18 });


    v1 = getMergedLineSegments(v);

    sort(v1.begin(), v1.end());

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i][0] << " , " << v1[i][1] << '\n';
    }

    
    return 0;
}

