# [문자열 겹쳐쓰기](https://school.programmers.co.kr/learn/courses/30/lessons/181943)
## 풀이
+ 바꿀 이외의 앞 부분, 바꿀 부분, 바꿀 이외의 뒷 부분으로 구분하여 answer를 구성한다.
+ 앞 부분(0, s), 바꿀 부분(s, 바꿀 부분의 길이), 뒷 부분(바꿀 부분의 길이 + s) 이런 형태로 answer에 순차적으로 더한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    answer += my_string.substr(0,s);
    answer += overwrite_string;
    answer += my_string.substr(overwrite_string.length() + s,my_string.length());
    return answer;
}
```