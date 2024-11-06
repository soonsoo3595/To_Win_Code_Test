#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int j = 0; j < s.length(); j++)
    {
        rotate(s.begin(), s.begin() + 1, s.end());
        
        stack<char> stk;
    
        for(int i = 0; i < s.length(); i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
            }
            else
            {
                if(s[i] == ')' && stk.top() == '(')
                {
                    stk.pop();
                }
                else if(s[i] == '}' && stk.top() == '{')
                {
                    stk.pop();
                }
                else if(s[i] == ']' && stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    stk.push(s[i]);
                }
            }
        }
        if(stk.empty())
        {
            answer++;
        }
    }
    return answer;
}