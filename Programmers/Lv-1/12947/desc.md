# [하샤드 수](https://school.programmers.co.kr/learn/courses/30/lessons/12947)
## 풀이
주어진 숫자 x가 x의 자릿수 합으로 x가 나뉘어진다면 그것은 하샤드 수이다.
+ 자릿수의 합을 구하는 함수를 구현
+ x와 자릿수의 합이 나누어 떨어지지 않는다면 answer를 반전하고 값 반환
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
int digit_sum(int n)
{
    int result = 0;
    while(n)
    {
        result += n%10;
        n /= 10;
    }
    return result;
}
bool solution(int x) {
    bool answer = true;
    if(x % digit_sum(x))answer = !answer;
    return answer;
}
```
