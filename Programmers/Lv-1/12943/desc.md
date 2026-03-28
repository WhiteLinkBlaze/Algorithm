# [콜라츠 추측](https://school.programmers.co.kr/learn/courses/30/lessons/12943)
## 풀이
+ 과정을 처리한 횟수만 기록하여 추가적인 처리를 해준다.
```
1-1. 입력된 수가 짝수라면 2로 나눕니다. 
1-2. 입력된 수가 홀수라면 3을 곱하고 1을 더합니다. 
2. 결과로 나온 수에 같은 작업을 1이 될 때까지 반복합니다. 
```
+ 연산 횟수가 500회가 되거나 넘으면 반복을 그만한다.
+ 결과에 연산 과정 중이던 값이 1이 아니라면 -1을 결과에 적용한다.
+ 아니라면 연산횟수를 결과에 적용한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int cnt = 0;
    long long number = num;
    while(number != 1 && cnt < 500)
    {
        if(number%2 == 0) number = number/2;
        else if(number%2 == 1)number = number*3+1;
        cnt++;
    }
    answer = number!=1 ? -1 : cnt;
    return answer;
}
```
