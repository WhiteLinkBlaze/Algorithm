# [로그인 성공?](https://school.programmers.co.kr/learn/courses/30/lessons/120883)
## 풀이
+ 순차적으로 탐색을 진행하고 id가 같은 경우
	+ pw도 같다면 login
	+ pw가 다르다면 wrong pw 를 반환한다.
+ id를 찾지 못했다면 answer의 길이는 0이다.
+ 길이가 0이라면 answer에 fail을 저장하고 반환한다.

map이나 unordered_map에 대해 알아보자
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    string id = id_pw[0];
    string pw = id_pw[1];
    for(vector<string> element : db)
    {
        if(id.compare(element[0]) == 0)
        {
            if(pw.compare(element[1]) == 0)
                answer = "login";
            else
                answer = "wrong pw";
            break;
        }
    }
    if(answer.length() == 0)
        answer = "fail";
    return answer;
}
```