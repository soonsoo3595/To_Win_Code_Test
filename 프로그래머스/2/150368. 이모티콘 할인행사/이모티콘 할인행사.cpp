#include <bits/stdc++.h>

using namespace std;

int sales[4] = {10, 20, 30, 40};
vector<vector<int>> saleList;

void Combination(int depth, vector<int>& v, int size)
{
    if(v.size() == size)
    {
        saleList.push_back(v);
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        v.push_back(i);
        Combination(depth + 1, v, size);
        v.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    // 세일 조합
    vector<int> v;
    Combination(0, v, emoticons.size());
    
    int answer_sum = 0;         // 정답이 될 이모티콘 총 매출
    int answer_people = 0;      // 정답이 될 이모티콘 플러스 가입자 수
    
    for(int i = 0; i < saleList.size(); i++)
    {
        int sum = 0;            // 현재 세일 조합에서 이모티콘 매출
        int people = 0;         // 현재 세일 조합에서 이모티콘 플러스 가입자 수
        
        for(int j = 0; j < users.size(); j++)
        {
            int price = 0;      // 현재 사용자가 이모티콘을 구매하는 가격
            
            for(int k = 0; k < saleList[i].size(); k++)
            {
                int sale = sales[saleList[i][k]];
                
                if(users[j][0] <= sale)
                {
                    price += (emoticons[k] * (100 - sale) / 100);
                }
            }
            
            if(price >= users[j][1])
            {
                price = 0;
                people++;
            }
            else
            {
                sum += price;
            }
        }
        
        if (answer_people < people || (answer_people == people && answer_sum < sum)) 
        {
            answer_people = people;
            answer_sum = sum;
        }
    }
    
    answer.push_back(answer_people);
    answer.push_back(answer_sum);
    
    return answer;
}