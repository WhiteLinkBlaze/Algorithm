# [x만큼 간격이 있는 n개의 숫자](https://school.programmers.co.kr/learn/courses/30/lessons/12954)
## 풀이
x가 2라면 2,4,6,8... 이런식이고, 5라면 5,10,15,20 이므로 ($x\times i$)로 결과를 구성함

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for(int i = 1; i <= n; i++)answer.push_back(x*i);
    return answer;
}
```