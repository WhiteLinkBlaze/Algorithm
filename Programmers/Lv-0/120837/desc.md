# [개미 군단](https://school.programmers.co.kr/learn/courses/30/lessons/120837)
---
## 풀이
장군 개미(5), 병정 개미(3), 일 개미(1) 이므로, 가장 큰 수의 개미로 먼저 나눠서 몫을 answer에 더하고 나머지를 hp에 저장하도록하고 다음 개미로 넘어간다. 일개미의 공격력이 1이므로 결국에는 전부 나누어 떨어지게 된다.

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    int ants[3] = {5,3,1};
    for(int i = 0; i < 3; i++)
    {
        answer += hp/ants[i];
        hp = hp%ants[i];
    }
    
    return answer;
}
```