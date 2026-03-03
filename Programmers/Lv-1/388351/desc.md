# [유연근무제](https://school.programmers.co.kr/learn/courses/30/lessons/388351)
## 풀이
시간 값이 int형으로 표현되어 주어지지만 그대로 사용해서는 안 된다.
+ 출근 희망 + 10분을 표현하기 위해 end_min, end_hour로 한 번 변환했다가 end_time으로 합침
+ 일주일간 늦었는지 확인하기 위해 today값은 1씩 증가 시키면서 0 ~ 6(월 ~ 일)사이로 고정
+ 토요일, 일요일은 카운트 하지 않기 때문에 today가 4(금요일)보다 크다면 넘어간다.
+ 실제 출근 기록이 출근 희망 + 10분을 넘었다면 check값을 전환(true - > false)하고 넘어간다.
+ check가 true 라면 정상적으로 출근한 것이므로 answer에 추가함

## 코드
```cpp
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    startday--;
    for(int i = 0; i < schedules.size(); i++)
    {
        bool check = true;
        int end_min = schedules[i]%100 + 10;
        int end_hour = (schedules[i]/100)%24 + end_min/60;
        int end_time = end_hour*100 + end_min%60;
        for(int j = 0; j < timelogs[i].size() && check; j++)
        {
            int today = (startday + j) % 7;
            if(today > 4)continue;
            if(timelogs[i][j] > end_time)
            {
                check = !check;
            }
        }
        if(check)answer++;
    }
    return answer;
}
```
