#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    a = a - 1;
    b = b - 1;
    
    while(a != b)
    {
        a /= 2;
        b /= 2;
        answer++;
    }

    return answer;
}

// 1 2 3 4 5 6 7 8 -> 1
// 1     2   3 4   -> 2
//       1     2   -> 3