# [소수 찾기](https://school.programmers.co.kr/learn/courses/30/lessons/12921)
## 풀이
1부터 숫자 n 사이에 있는 소수의 개수를 반환하는 문제
- n은 2이상 1000000이하의 자연수입니다.

처음에는 에라토스를 쓸까하다가 메모리 제한이 어느정도인지 몰라서 매번 소수를 계산하는 방법을 썼으나, 매번 소수를 계산하니 효율성에서 시간 초과가 발생한다.

그래서 에라토스테네스의 체 방법을 사용해서 풀었다.
+ 에라토스테네스의 체는 미리 목표하는 숫자까지의 공간을 마련하고 해당 공간에 소수인지 아닌지를 기록해두는 것이다.
+ 숫자가 필요할 때 해당 index 요소에 접근하는 것으로 여러번 소수인지를 묻는 문제에서 편리하다.
	+ 단 공간을 많이 차지한다.

에라토스테네스의 체는 2부터 n 사이의 수 x와 1의 곱을 제외한 x의 배수 전부를 지우는 것으로 소수가 아닌 숫자들을 걸러낼 수 있다.
+ 소수는 1과 자신과의 곱으로만 구성됨
## 코드
```cpp
#include <string>
#include <vector>
#include <cmath>

using namespace std;
bool eratos[1'000'001];
void initEratos(int num)
{
    for(int i = 2; i <= num; i++)
    {
        for(int k = 2; i*k <= num; k++)
        {
            eratos[i*k]=true;
        }
    }
}
int solution(int n) {
    int answer = 0;
    initEratos(n);
    for(int i = 2; i <= n; i++)if(!eratos[i])answer++;
    return answer;
}
```
