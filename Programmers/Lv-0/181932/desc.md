# [코드 처리하기](https://school.programmers.co.kr/learn/courses/30/lessons/181932)
## 풀이
+ mode에 따라 행동이 달라지도록 구현을 해야한다.
+ code에 대해 순차 탐색을 진행했고 mode를 int로 구성해서 `code[i]`가 1일 때 mode의 값이 1 과 0 둘 중 하나로 전환되게 했다.
+ 나머지는 기본적인 요구사항 반영
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    int mode = 0;
    for(int i=0;i<code.length();i++)
    {
        if(code[i] != '1' && i % 2 == mode)
            answer+=code[i];
        else if(code[i] == '1')
            mode = !mode;
    }
    if(answer.compare("") == 0)
        answer = "EMPTY";
    return answer;
}
```