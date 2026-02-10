# [소인수분해](https://school.programmers.co.kr/learn/courses/30/lessons/120852)
## 풀이
소인수분해를 하는 코드를 작성한다. 12의 경우 $2\times2\times3$으로 표현이 된다.
+ 소수로 나눌 수 있으면 계속 나눈다.

에라토스테네스의 체의 방법을 활용하여 풀었다. 

2로 나눌 수 있는 경우 2로 계속 해서 나눈다. 
+ 이렇게 되면 이후 2의 배수에 해당하는 값들은 n과 나누어 떨어지지 않게 된다.

다음 차례인 3의 경우 n에서 3의 배수를 모두 제거하게 된다. 

다음 차례인 i의 경우 n에서 i의 배수를 모두 제거하게 된다. 

이렇게 수를 올려가면 결국 소수만으로 n을 나눌 수 있게 된다.
### 발전
+ 소인수 분해를 하는 과정에서 n은 점점 작아지게 된다. 이를 표현하기 위해 n/=i를 하게 되면 값의 연산 범위를 줄일 수 있다.
+ 소수를 구하기 위해 값의 범위를 sqrt(n)을 했던 것 처럼 i*i를 통해 구할 값의 범위를 sqrt(n)과 같은 범위로 줄일 수 있다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    for(int i = 2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            answer.push_back(i);
            while(n%i == 0)
                n/=i;
        }
    }
    if(n>1)
        answer.push_back(n);
    return answer;
}
```