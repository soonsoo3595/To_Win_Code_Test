#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int parent[10004];
int profit[10004];
map<string, int> info;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i = 0; i < enroll.size(); i++)
    {
        info[enroll[i]] = i;
    }
    
    for(int i = 0; i < referral.size(); i++)
    {
        if(referral[i] == "-")
        {
            parent[i] = -1;
        }
        else
        {
            parent[i] = info[referral[i]];
        }
    }
    
    for(int i = 0; i < seller.size(); i++)
    {
        int sellerNum = info[seller[i]];
        int price = amount[i] * 100;
        profit[sellerNum] += price * 0.9;
        
        while(parent[sellerNum] != -1)
        {
            sellerNum = parent[sellerNum];
            price = price * 0.1;
            profit[sellerNum] += ceil(price * 0.9);
        }
    }
    
    for(int i = 0; i < enroll.size(); i++)
    {
        answer.push_back(profit[i]);
    }
    
    return answer;
}