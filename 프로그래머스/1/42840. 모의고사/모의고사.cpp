#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> count = {0, 0, 0};
    vector<int> one = {1,2,3,4,5};
    vector<int> two = {2,1,2,3,2,4,2,5};
    vector<int> three = {3,3,1,1,2,2,4,4,5,5};
    
    int len = answers.size();
    
    for(int i = 0; i < len; i++)
    {
        if(answers[i] == one[i % 5])
        {
            count[0]++;
        }
        if(answers[i] == two[i % 8])
        {
            count[1]++;
        }
        if(answers[i] == three[i % 10])
        {
            count[2]++;
        }
    }
    
    int max = *max_element(count.begin(), count.end());
    
    for(int i = 0; i < count.size(); i++)
    {
        if(max == count[i])
            answer.push_back(i+1);
    }
    
    return answer;
}