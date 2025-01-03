#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i = 1; ; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(i * j == brown + yellow && 2 * i + 2 * j - 4 == brown)
            {
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }
    
    return answer;
}