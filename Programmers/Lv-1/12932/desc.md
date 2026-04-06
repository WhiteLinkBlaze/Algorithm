# [자연수 뒤집어 배열로 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/12932)
## 풀이
+ 1의 자리의 숫자부터 추출하여 `answer`를 구성하면된다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while(n)
    {
        answer.push_back(n%10);
        n = n/10;
    }
    return answer;
}
```