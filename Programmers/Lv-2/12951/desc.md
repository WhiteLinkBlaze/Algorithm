# [JadenCase 문자열 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/12951)
## 풀이
JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다.

+ 문자열을 받고 전부 소문자로 바꾼다.
+ check 변수를 만들어서, 공백을 만나면 true로, 아니라면 false로 바뀌도록 한다.
+ 공백 뒤에 바로 만나는 문자를 대문자로 바꾼다.
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    bool check = true;
    for_each(s.begin(), s.end(), [](auto& c){c = tolower(c);});
    for(char& ch : s)
    {
        if(check)
        {
            if(ch >='a' && ch <= 'z')
            {
                ch = toupper(ch);
            }
            else if(ch == ' ')continue;
            check = false;
        }
        else
        {
            if(ch == ' ')check = true;
        }
    }
    answer = s;
    return answer;
}
```