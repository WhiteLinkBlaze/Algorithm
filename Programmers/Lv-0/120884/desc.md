# [치킨 쿠폰](https://school.programmers.co.kr/learn/courses/30/lessons/120884)
## 풀이
+ answer는 쿠폰으로 치킨을 시킨 횟수이다.
+ coupon/10 만큼 매번 시키게 되고
+ coupon은 coupon/10 + coupon%10; 만큼 남게 된다.
+ 이 coupon으로 더 못 시킬 때까지 반복하여 answer를 구성한다.

## 코드

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int coupon = chicken;
    while(coupon >= 10)
    {
        answer += coupon/10;
        coupon = coupon/10 + coupon%10;
    }
    return answer;
}
```