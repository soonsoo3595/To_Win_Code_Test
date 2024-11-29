#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string special = "-_.";

string solution(string new_id) {
    string answer = "";
    
    answer = new_id;
    
    // 1단계
    for(int i = 0; i < answer.size(); i++)
    {
        if(isupper(answer[i]))
        {
            answer[i] = tolower(answer[i]);
        }
    }
    
    string temp = "";
    
    // 2단계
    for(int i = 0; i < answer.size(); i++)
    {
        if(isalpha(answer[i]) || isdigit(answer[i]))
        {
            temp += answer[i];
            continue;
        }
        
        if(find(special.begin(), special.end(), answer[i]) != special.end())
        {
            temp += answer[i];
        }
    }
    
    answer = temp;
    
    // 3단계
    temp = "";
    int count = 0;
    for(int i = 0; i < answer.size(); i++)
    {
        if(answer[i] == '.')
        {
            count++;
        }
        else
        {
            if(count >= 1)
            {
                temp += '.';
            }
            
            temp += answer[i];
            count = 0;
        }
    }
    
    answer = temp;
    // 4단계
    temp = "";
    
    for(int i = 0; i < answer.size(); i++)
    {
        if(i == 0 || i == answer.size() - 1)
        {
            if(answer[i] == '.')
                continue;
        }
        
        temp += answer[i];
    }
    
    answer = temp;
    
    // 5단계
    if(answer == "")
    {
        answer = "a";
    }
    
    temp = "";
    // 6단계
    if(answer.length() >= 16)
    {
        temp = answer.substr(0, 15);
        
        if(temp.back() == '.')
        {
            temp = temp.substr(0, 14);
        }
        
        answer = temp;
    }
    
    // 7단계
    if(answer.length() <= 2)
    {
        temp = answer;
        
        while(temp.length() < 3)
        {
            temp += answer.back();
        }
        
        answer = temp;
    }
    
    return answer;
}