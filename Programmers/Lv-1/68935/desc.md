# [3진법 뒤집기](https://school.programmers.co.kr/learn/courses/30/lessons/68935)
## 풀이
숫자를 어떤 진법으로 변환하게 되면 뒤집어진 n진법으로 나온다. 따라서 바로 진법 변환을 위한 연산을 수행하고, 해당 순서로 처리한다.

앞의 것부터 처리해도 되지만 $3^0$부터 처리하고 싶어서 코드가 조금 길어졌다.

## 코드
```cpp
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> trinary;
    while(n > 0)
    {
        trinary.push_back(n%3);
        n/=3;
    }
    for(int i=trinary.size()-1; i>=0; i--)
    {
        answer += pow(3,trinary.size() - 1 - i) * (trinary[i]);
    }
    return answer;
}
```