#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long max_time = *max_element(times.begin(), times.end());
    
    long long left = 1;
    long long right = n * max_time;
    
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        long long count = 0;
        
        for(long long time : times)
        {
            count += (mid / time);
        }
        
        if(count >= n)
        {
            answer = mid;
            right = mid - 1;
        }
        else if(count < n)
        {
            left = mid + 1;
        }
        
    }
    
    return answer;
}