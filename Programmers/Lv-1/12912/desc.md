# [두 정수 사이의 합](https://school.programmers.co.kr/learn/courses/30/lessons/12912)
## 풀이
두 정수 사이의 모든 숫자의 합을 구합니다.
+ a,b 사이의 우열을 모릅니다. -> a가 큰 값이도록 처리했다.
+ 1부터 정수 사이의 합을 구합니다.

(a > b) (0부터 a까지의 합) - (0부터 b-1까지의 합)을 구하면 사이의 합을 구할 수 있다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
long long sigma(long long n)
{
    return n*(n+1)/2;
}
long long solution(int a, int b) {
    long long answer = 0;
    if(a == b)return a;
    if(a < b)
    {
        int t = a;
        a = b;
        b = t;
    }
    answer = sigma(a) - sigma(b-1);
    return answer;
}
```
```cpp title='다른 사람 풀이'
long long solution(int a, int b) {
    long long answer = 0;
    answer = (long long)(a+b)*(abs(a-b)+1)/2;
    return answer;
}
```