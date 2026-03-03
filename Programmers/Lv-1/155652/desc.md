# [둘만의 암호](https://school.programmers.co.kr/learn/courses/30/lessons/155652)
## 풀이
문자열 s를 index값 만큼 밀어야한다. 단, skip에 포함된 문자라면 카운트하지 않는다.
+ s에서 문자를 하나씩 뽑는다.(ch)
+ 아래의 단계를 index회 반복한다.
	+ ch를 1증가 시키고 ch의 범위를 0~25 사이로 만들고 `+'a'`를 통해 다시 a~z 사이의 값으로 바꾼다.
	+ 그런데 이 문자가 skip에 포함된 문자라면 카운팅 하지 않는다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(char ch : s)
    {
        int start_idx = 0;
        while(start_idx < index)
        {
            ch = (ch + 1 - 'a') % (26);
            ch += 'a';
            if(skip.find(ch) == string::npos)start_idx++;
        }
        answer.push_back(ch);
    }
    return answer;
}
```