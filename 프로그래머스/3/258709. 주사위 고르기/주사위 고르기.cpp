#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> selectDice;
vector<vector<int>> indexCombi;

float prob;

void Combi(int start, int depth, vector<int>& A_dices)
{
    if(A_dices.size() == depth)
    {
        selectDice.push_back(A_dices);
        return;
    }
    
    for(int i = start; i < N; i++)
    {
        A_dices.push_back(i);
        Combi(i + 1, depth, A_dices);
        A_dices.pop_back();
    }
}

void DiceSum(vector<vector<int>>& dice, vector<int>& select, int idx, int sum, vector<int>& result)
{
    if(idx == select.size())
    {
        result.push_back(sum);
        return;
    }
    
    for(int i = 0; i < 6; i++)
    {
        DiceSum(dice, select, idx + 1, sum + dice[select[idx]][i], result);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    N = dice.size();
    
    // 주사위를 선택하는 조합
    // selectDice 초기화
    vector<int> v;
    Combi(0, N / 2, v);
    
    // 주사위를 나눈 경우의 수
    for(int i = 0; i < (int)selectDice.size() / 2; i++)
    {
        // A와 B가 나눈 주사위를 먼저 구함
        vector<int> A, B;
        
        for(int j = 0; j < N; j++)
        {
            if(find(selectDice[i].begin(), selectDice[i].end(), j) != selectDice[i].end())
            {
                A.push_back(j);
            }
            else
            {
                B.push_back(j);
            }
        }
        
        vector<int> A_result;
        vector<int> B_result;
        
        DiceSum(dice, A, 0, 0, A_result);
        DiceSum(dice, B, 0, 0, B_result);
        
        sort(B_result.begin(), B_result.end());
        
        int victory = 0;
        int draw = 0;
        int defeat = 0;
        
        for(int A_sum : A_result)
        {
            auto lower = lower_bound(B_result.begin(), B_result.end(), A_sum);
            auto upper = upper_bound(B_result.begin(), B_result.end(), A_sum);
            
            victory += (lower - B_result.begin());
            draw += (upper - lower);
            defeat += (B_result.end() - upper);
        }
        
        float prob1 = (float)victory / (victory + draw + defeat);
        float prob2 = (float)defeat / (victory + draw + defeat);
        
        if(prob1 > prob2)
        {
            if(prob < prob1)
            {
                prob = prob1;
                answer = A;
            }
        }
        else
        {
            if(prob < prob2)
            {
                prob = prob2;
                answer = B;
            }
        }
    }
    
    for(int i = 0; i < answer.size(); i++)
    {
        answer[i]++;
    }
    
    return answer;
}