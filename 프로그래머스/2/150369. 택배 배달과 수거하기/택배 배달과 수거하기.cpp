#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;   // 최종 왕복 거리의 합 (결과값)
    
    int delivery = 0;     // 현재 남아 있는 배달 작업량
    int pickup = 0;       // 현재 남아 있는 수거 작업량
    int count = 0;        // 현재 위치에서 필요한 왕복 횟수 (트럭을 몇 번 왕복시켜야 하는지)   
    
    // 뒤에서부터(가장 먼 집부터) 탐색
    for(int i = n - 1; i >= 0; i--)
    {
        delivery -= deliveries[i];  // 배달해야 할 물량 추가
        pickup -= pickups[i];       // 수거해야 할 물량 추가
        
        // 현재 집까지 배달과 수거 작업이 모두 완료될 때까지 반복
        while(true)
        {
             // 배달과 수거 작업이 모두 끝난 경우 반복 종료
            if(delivery >= 0 && pickup >= 0) break;
            
            // 트럭이 왕복하면서 배달 및 수거할 수 있는 만큼 추가
            delivery += cap;    // 트럭 용량만큼 배달할 수 있는 작업량 확보
            pickup += cap;      // 트럭 용량만큼 수거할 수 있는 작업량 확보
            count++;            // 왕복 횟수 증가
        }
        
        // 현재 집까지의 왕복 거리 반영
        answer += (i + 1) * count * 2;      // 왕복 거리 = 거리 * 왕복 횟수 * 2
        count = 0;                          // 왕복 횟수 초기화 (다음 집에 대한 작업을 위해)
    }
    
    return answer;
}