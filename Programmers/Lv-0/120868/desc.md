# [삼각형의 완성조건 (2)](https://school.programmers.co.kr/learn/courses/30/lessons/120868)
## 풀이
a, b, c의 변이 있을 때 a, b는 알지만 c를 모를 경우
1. 가장 긴 변이 a인 경우: $a < b+c$ 이어야 한다.
2. 가장 긴 변이 c인 경우: $c < a+b$ 이어야 한다.

그렇다면 범위는 $a-b < c < a+b$ 가 된다.

따라서 개수는 $a + b - a + b - 1 = 2b - 1$
+ 알려진 최소 길이 * 2 - 1이 c가 가질 수 있는 정수형 길이의 개수이다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int min_side = min(sides[0], sides[1]);
    
    answer += min_side;
    answer += min_side-1;
    return answer;
}
```