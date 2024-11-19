#include <bits/stdc++.h>

using namespace std;
int visited[10];
map<string, int> m;
map<int, int> answer_map;

void Func(string number, string& numbers)
{
    if(m[number] == 1) return;
    if(number != "") 
    {
        m[number] = 1;
        answer_map[stoi(number)] = 1;
    }
    
    for(int i = 0; i < numbers.length(); i++)
    {
        if(visited[i]) continue;
        
        visited[i] = true;
        string numStr = number + numbers[i];
        Func(numStr, numbers);
        visited[i] = false;
    }
}

bool IsPrime(int n)
{
    if(n == 0 || n == 1) return false;
    
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    Func("", numbers);
    
    for(auto ans : answer_map)
    {
        if(IsPrime(ans.first))
            answer++;
    }
    
    return answer;
}