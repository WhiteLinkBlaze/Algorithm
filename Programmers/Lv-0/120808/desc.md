# [분수의 덧셈](https://school.programmers.co.kr/learn/courses/30/lessons/120808)
## 풀이
+ 두 분수를 더한다.
	+ 아래와 같은 형태로 분모(denominator), 분자(numerator)를 구성한다.
$$
b/a + d/c = {(bc+ad)}/ac
$$
+ 기약 분수로 나타낸다.
	+ 유클리드 호제법을 이용하여 최대공약수를 구하고, 최대 공약수를 이용하여 기약 분수를 구성한다.
```cpp
temp = gcd(numerator, denominator);
numerator = numerator/temp;
denominator = denominator/temp;
```

## 코드
```cpp
#include <string>
#include <vector>
#include <iostream>
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
vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int denominator = denom1*denom2;
    int numerator = numer1*denom2 + numer2*denom1;
    int temp = 0;
    temp = gcd(numerator, denominator);
    numerator = numerator/temp;
	  denominator = denominator/temp;
    answer.push_back(numerator);
    answer.push_back(denominator);
    return answer;
}
```
## 참고자료
+ [유클리드 호제법](https://ko.wikipedia.org/wiki/유클리드_호제법)