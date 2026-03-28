# [기사단원의 무기](https://school.programmers.co.kr/learn/courses/30/lessons/136798)
## 풀이
자기 번호의 약수의 개수가 무기의 공격력인데, 이 공격력이 제한수치를 초과하였다면 `power` 값으로 대체합니다.
+ 번호에 맞는 약수의 개수를 구합니다.
+ 약수의 개수가 제한수치를 초과하였다면 `power`값으로 바꿉니다.
+ 현재 무기의 공격력을 결과에 포함시킵니다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
int divisor(int num)
{
    int cnt = 0;
    for(int i = 1; i*i <= num; i++)
    {
        if(num%i)continue;
        else if(i*i == num)cnt++;
        else if(num%i == 0)cnt+=2;
    }
    return cnt;
}
int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i = 1; i <= number; i++)
    {
        int cur_power = divisor(i);
        if(cur_power > limit)cur_power = power;
        answer+=cur_power;
    }
    return answer;
}
```
