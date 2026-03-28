# [최대공약수와 최소공배수](https://school.programmers.co.kr/learn/courses/30/lessons/12940)
## 풀이
+ 두 수는 1이상 ==1,000,000==이하의 자연수입니다.

1. 유클리드 호제법으로 최대공약수를 구할 수 있다.
2. 최대공약수를 통해 최소공배수를 구할 수 있다.
$$
lcm(a,b) = \frac{|ab|}{gcd(a,b)}
$$
위의 최소공배수를 구하는 공식을 이용하기 위해 `int`형이 아닌 `long long`을 사용(값의 범위가 long long이 대략$10^{18} \sim 10^{-18}$이고, `int`은 $10^9 \sim 10^{-9}$)
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int euclidean(int a, int b)
{
    int r;
    while(r != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    long long temp;
    answer.push_back(euclidean(n,m));
    temp = (long long)n*m;
    temp /= answer[0];
    answer.push_back(temp);
    return answer;
}
```
