# [가운데 글자 가져오기](https://school.programmers.co.kr/learn/courses/30/lessons/12903)
## 풀이
문자열내에서 가운데 글자를 가져오는 문제인데, 문자열의 길이가 짝수이면 2개를 가져와야 한다.

짝수인 경우
+ pos-1 에서부터 2개의 문자를 추출해 `answer`에 추가
홀수인 경우
+ pos에 위치한 값을 `answer`에 추가
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int pos = s.length()/2;
    if(s.length()%2 == 0)
    {
        answer = s.substr(pos-1,2);
    }
    else answer = s[pos];
    return answer;
}
```
