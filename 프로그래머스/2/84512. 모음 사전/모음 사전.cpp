#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

char alpha[5] = {'A', 'E', 'I', 'O', 'U'};
vector<string> dict;

void DFS(int r, string s)
{
    if(s.size() == r)
    {
        dict.push_back(s);
        return;
    }
    
    for(int i = 0; i < 5; i++)
    {
        s.push_back(alpha[i]);
        DFS(r, s);
        s.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    
    DFS(1, "");
    DFS(2, "");
    DFS(3, "");
    DFS(4, "");
    DFS(5, "");
    
    sort(dict.begin(), dict.end());
    
    for(int i = 0; i < dict.size(); i++)
    {
        if(dict[i] == word)
        {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}