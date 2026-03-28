# [정수 내림차순으로 배치하기](https://school.programmers.co.kr/learn/courses/30/lessons/12933)
## 풀이
- `n`은 1이상 8000000000 이하인 자연수입니다.

값의 범위가 넓기 때문에 list로 하나씩 넣던가, 문자열로 만들던가 해서 처리를 한다.
+ 문자열로 바꾼다.
+ 문자열을 내림차순으로 정렬한다.
+ 문자열을 `long long`형으로 변환한다.
## 코드
```cpp title='다른 분의 풀이 참고하고 수정한 풀이 진짜 깔끔'
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string number = to_string(n);
    sort(number.begin(), number.end(), greater<char>());
    answer = stoll(number);
    return answer;
}
```
