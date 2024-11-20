#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    
    vector<vector<int>> adj(n + 1, vector<int>());
    
    for(int i = 0; i < wires.size(); i++)
    {
        adj[wires[i][0]].push_back(wires[i][1]);
        adj[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i = 0; i < wires.size(); i++)
    {
        vector<int> visited(n + 1, 0);
        
        queue<int> q;
        q.push(1);
        
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            visited[top] = 1;
            
            for(int nextTop : adj[top])
            {
                if(visited[nextTop] || (top == wires[i][0] && nextTop == wires[i][1]) || (top == wires[i][1] && nextTop == wires[i][0])) continue;
                
                q.push(nextTop);
            }
        }
        
        int c1 = 0, c2 = 0;
        
        for(int j = 1; j <= n; j++)
        {
            if(visited[j] == 1) c1++;
            else c2++;
        }
        
        answer = min(answer, abs(c1 - c2));
    }
    
    
    return answer;
}