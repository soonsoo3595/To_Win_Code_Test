#include <bits/stdc++.h>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int t_length = t.length();
    int p_length = p.length();
    long long p_num = stol(p);
    
    for(int i = 0; i <= t_length - p_length; i++)
    {
        string s = t.substr(i, p_length);
        
        long long num1 = stol(s);
        
        if(num1 <= p_num)
        {
            answer++;  
        }
    }
    
    return answer;
}