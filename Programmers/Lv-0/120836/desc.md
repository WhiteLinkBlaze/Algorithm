# [순서쌍의 개수](https://school.programmers.co.kr/learn/courses/30/lessons/120836)
## 풀이
+ 순서쌍은 원하는 숫자의 제곱근까지 확인하면 시간을 많이 단축할 수 있다.
	+ 대표적 예시 16 : (1,16), (2,8), (4,4), (8,2), (16,1)
+ 따라서 `max = sqrt(n);`만큼 1부터 숫자를 올려 나눌 수 있다면 answer에 추가한다.
+ 제곱근까지 검사 했다면, 제곱근이 포함되는 순서쌍과 포함되지 않는 순서쌍을 구분해야한다.
	+ (1, 20), (2, 10), (4, 5), (5, 4), (10, 2), (20, 1)의 경우 단순 x2로 되지만
	+ (1,16), (2,8), (4,4), (8,2), (16,1)은 하나 더 들어가게 된다.
## 코드
```cpp
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int max = (int)floor(sqrt(n));
    for(int i=1; i <= max; i++)
    {
        if(n%i == 0)
            answer++;
    }
    
    if(n == max*max) answer = answer + (answer-1);
    else answer *=2;
    return answer;
}
```