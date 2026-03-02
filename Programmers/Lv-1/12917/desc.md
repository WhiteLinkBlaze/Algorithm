# [문자열 내림차순으로 배치하기](https://school.programmers.co.kr/learn/courses/30/lessons/12917)
## 풀이
정렬합니다.
```cpp
//내림차순 정렬
sort(s.begin(),s.end, greater<char>());
```

## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    sort(s.begin(),s.end(),greater<char>());
    answer =  s;
    return answer;
}
```
