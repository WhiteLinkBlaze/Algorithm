# [유한소수 판별하기](https://school.programmers.co.kr/learn/courses/30/lessons/120878)
## 용어
+ 유한 소수('finite decimal' or 'terminating decimal')
	+ 소수점 아래 숫자가 계속되지 않고 유한개인 소수
	+ 기약분수로 나타내었을 때, 분모의 소인수가 2와 5만 존재해야 한다.
+ 무한 소수('infinite decimal' or 'non-terminating decimal')
	+ 소수점 아래 숫자가 무한히 계속되는 소수
## 풀이
+ 기약분수를 구한다.(유클리드 호제법 사용)
+ 분모만 추출해서 소인수분해한다. 함수`bool finite(...)` 구성
+ 분자가 분모로 나누어 떨어져 정수가 되는지 확인한다.


## 코드
```cpp
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a,int b)
{
    int r;
    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

bool finite( const int num)
{
    int target = num;
    for(int i = 2; i <= target; i++)
    {
        if(target%i == 0)
        {
            if(i%5 != 0 && i%2 != 0) return false;
            target/=i;
            i = 1;
        }
    }
    return true;
}
int solution(int a, int b) {
    int answer = 0;
    int commonFactor = gcd(a,b);
    a/=commonFactor;
    b/=commonFactor;
    
    answer = finite(b) ? 1 : 2;
    answer = a%b==0 ? 1 : answer;
    return answer;
}
```
## 참고자료
+ [유한 소수](https://ko.wikipedia.org/wiki/소수_(기수법))