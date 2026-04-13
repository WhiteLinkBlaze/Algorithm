# [문자열 다루기 기본](https://school.programmers.co.kr/learn/courses/30/lessons/12918)
> 문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성돼있는지 확인해주는 함수
## 풀이
+ 길이가 우선 조건에 맞는지 검사한다.
+ 길이가 맞은 상태에서 문자열 내의 요소를 검사하여 숫자인 문자들이 섞여있는지 검사한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = false;
    if(s.length() == 4 || s.length() == 6)
    {
        answer = true;
        for(int i=0; i<s.length(); i++)
        {
            if(!('0' <= s[i] && s[i] <= '9'))
            {
                answer = false;
                break;
            }
        }
    }
    return answer;
}
```
