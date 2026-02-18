# [구슬을 나누는 경우의 수](https://school.programmers.co.kr/learn/courses/30/lessons/120840)
## 풀이
n개 중 r개를 뽑는다.

$$
_{n}C_r = \frac{n!}{(n-k)!k!}
$$

+ 재귀함수로 풀 수도 있지만 depth가 어디까지 허용될지도 모르고, 메모리 할당에 따라 허용되는 범위가 있어서 제외
+ 무작정 식을 구현하면 overflow가 생겨서 원하는 값을 얻을 수 없음
+ int 형으로는 풀이 과정에서 overflow가 생길 가능성이 있음 (`double, long long, __int128_t`)
	+ `double`: $[\pm 1.7 \times 10^{-308}, 1.7 \times 10^{+308}]$
	+ `long long`: $\pm 9 \times 10^{18}$
	+ `__int128_t`: $\pm 1.7 \times 10^{38}$

$$
_{30}C_{15} = 155117520
$$

곱하기와 나머지 단계를 동시에 할 수 있는 공통된 구간을 생각하고 해당 구간에서 풀어야함
+ 공통 범위 (n-k) or k
+ 곱하기는 top-down, 나누기는 bottom-up하게 되면 k만큼의 나누기 횟수가 보장된다.

$$
\frac{n*(n-1)(n-2)...(n-k+1)}{k(k-1)(k-2)..}
$$
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    int answer = 1;
    long long dummy = 1;
		int k = min(balls - share, share);
    for(int i = 0; i < k; i++)
    {
        dummy *= (balls-i);
        dummy /= (i+1);
    }
    answer = dummy;
    return answer;
}
```
