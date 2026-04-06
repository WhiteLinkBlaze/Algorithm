# [콜라 문제](https://school.programmers.co.kr/learn/courses/30/lessons/132267)
## 풀이
+ 콜라 n개를 가지고 있을 때 a개의 빈 병을 주면 b개의 콜라를 받는다.
+ `n/a*b`개의 빈 병을 새로 얻을 수 있는 셈이다. 
+ 가지고 있는 빈 병 수와 합해야 한다.(`bottle = bottle/a*b + bottle%a`)
+ 이 과정 중에서 새로 콜라를 얻은 개수를 세야하는 것
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int bottle = n;
    while(bottle >= a)
    {
        answer += bottle/a*b;
        bottle = bottle/a*b + bottle%a;
    }
    return answer;
}
```
```cpp title='다른 사람 풀이'
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = (n-b)/(a-b)*b;
    return answer;
}
```
