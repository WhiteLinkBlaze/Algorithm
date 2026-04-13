# [나누어 떨어지는 숫자 배열](https://school.programmers.co.kr/learn/courses/30/lessons/12910)
## 풀이
+ 숫자를 하나씩 검사하여, `divisor`로 나누어 떨어지는 지 확인하고 나누어 떨어지면 `answer`에 포함 시킨다.
+ `answer`에 값이 없다면 -1을 저장한다.
+ 완성한 answer를 정렬한다.
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int a : arr)
    {
        if(a % divisor == 0)answer.push_back(a);
    }
    if(answer.size() == 0)answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}
```
