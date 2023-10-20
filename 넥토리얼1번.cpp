#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

vector<int> autocompletes(vector<string> inputs) {

    vector<int> answer;

    for (int i = 0; i < inputs.size(); i++)
    {
        int ret = 0;

        if (i >= 1)
        {
            for (int j = 0; j < inputs[i].size(); j++)
            {
                string s = inputs[i].substr(0, j + 1);
                if (m[s] != 0)
                {
                    ret = m[s];
                }
            }

            if (ret == 0)
                ret = i;
        }

        for (int j = 0; j < inputs[i].size(); j++)
        {
            string s = inputs[i].substr(0, j + 1);
            m[s] = i + 1;
        }

        answer.push_back(ret);
    }

    return answer;
}

int main()
{
    vector<string> inputs;
    inputs.push_back("000");
    inputs.push_back("1110");
    inputs.push_back("01");
    inputs.push_back("001");
    inputs.push_back("110");
    inputs.push_back("11");


    vector<int> answer = autocompletes(inputs);

    

    for (int i : answer)
    {
        cout << i << ' ';
    }

    return 0;
}

