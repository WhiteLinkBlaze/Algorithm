# [이상한 문자 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/12930)
## 풀이
```
#include <cctype>
tolower(), touppwer()
```
문자를 하나씩 탐색하여 해당 인덱스가 짝수면 대문자, 홀수면 소문자로 표현
+ cnt는 공백을 만났을 경우 짝수 홀수가 한 칸씩 밀리는 것을 반영했다.
## 코드
```cpp
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 0;
    for(int i = 0; i < s.length(); i++)
    {
        char ch;
        if(s[i] == ' ')cnt = i%2 + 1;
        if(i%2 == cnt%2)ch = toupper(s[i]);
        else ch = tolower(s[i]);
        answer.push_back(ch);
    }
    return answer;
}
```