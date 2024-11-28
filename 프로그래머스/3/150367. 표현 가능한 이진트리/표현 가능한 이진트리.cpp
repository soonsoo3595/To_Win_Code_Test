#include <bits/stdc++.h>

using namespace std;

string GetBinary(long long num)
{
    string ret = "";
    
    while(num > 1)
    {
        ret += ((num % 2) + '0');
        
        num /= 2;
    }
    
    if(num % 2 == 1)
        ret += "1";
    
    reverse(ret.begin(), ret.end());
    
    return ret;
}

bool Tree(string& binary, int start, int end)
{
    if(start > end)
    {
        return true;
    }
    
    int root = (start + end) / 2;
    
    if (binary[root] == '0')
    {
        for (int i = start; i <= end; i++)
        {
            if (binary[i] == '1') return false;
        }
    }
    
    bool left = Tree(binary, start, root - 1);
    bool right = Tree(binary, root + 1, end);
    
    return (left && right);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        string binary = GetBinary(numbers[i]);
        
        int count = binary.size();
        int k = 0;
        
        while(count > (1 << k) - 1)
        {
            k++;
        }
        
        while(binary.size() != (1 << k) - 1)
        {
            string temp = "0";
            temp += binary;
            binary = temp;
        }
        
        if(Tree(binary, 0, binary.size() - 1))
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    return answer;
}