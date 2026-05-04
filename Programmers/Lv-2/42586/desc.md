# [기능 개발](https://school.programmers.co.kr/learn/courses/30/lessons/42586#)

## 풀이
+ 앞에서부터 순차적으로 (기능 개발에 필요한 일 수 - 기능 개발에 착수한 일 수) 를 구합니다.
+ 위의 값이 0이라면 순번이 늦어져 이미 처리된 작업입니다. answer 마지막 요소에 +1 합니다.
+ 0이하가 아니라면 오래 걸리는 작업입니다. 필요한 일 수를 기능 개발에 착수한 일 수 days에 누적합니다.
    + 그리고 answer에 1을 기록합니다.
+ 위의 작업을 반복하고 만들어진 answer를 반환합니다.

## 코드
```cpp
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int days = 0;
    int required_days = 0;
    for(int i = 0; i < progresses.size(); i++)
    {
        required_days = max((99 - progresses[i]) / speeds[i] + 1 - days, 0);
        if(required_days == 0) answer.back()++;
        else
        {
            days += required_days;
            answer.push_back(1);
        }
    }
    return answer;
}
```