# [시저 암호](https://school.programmers.co.kr/learn/courses/30/lessons/12926)
> 어떤 문장의 각 알파벳을 일정한 거리만큼 밀어서 다른 알파벳으로 바꾸는 암호화 방식을 시저 암호라고 합니다.
## 풀이
+ 문자열 내에서 알파만 골라내어 n번 밀어냅니다.
+ pos를 통해 소문자인지, 대문자인지 위치를 기록합니다.
+ `text-=pos`를 통해 기존 문자의 위치를 뽑아냅니다.
+ `(text + pos)%26`를 통해 바뀔 위치를 만듭니다.
+ 만들어낸 위치를 기존 소문자 범주인지 대문자 범주인지를 적용하기 위해 `pos + text`를 적용합니다.
## 코드
```cpp
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(char text : s)
    {
        int pos = 0;
        
        if(text >= 'a' && text <= 'z') pos = 'a';
        else if( text >= 'A' && text <= 'Z') pos = 'A';
        else {
            answer += ' ';
            continue;
        }
        text -= pos;
        answer.push_back((text+n)%26+pos);
    }
    return answer;
}
```