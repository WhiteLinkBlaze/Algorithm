# [숫자 문자열과 영단어](https://school.programmers.co.kr/learn/courses/30/lessons/81301)
## 풀이
+ 특정 문자열을 찾아서 그것을 `replace` 합니다.
+ 미리 숫자 영단어들을 기록한다.
+ 해당 문자열들을 모두 검색한다.
	+ 있다면 -> 숫자로 변경하고 다시 검색
	+ 없다면 -> 넘어감
+ 과정을 완료한 문자열을 숫자로 변환하여 반환
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string number = "";
    vector<string> str = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    
    int i = 0;
    while(i < str.size())
    {
        if(s.find(str[i])!= string::npos)
        {   
             s.replace(s.find(str[i]), str[i].length(), to_string(i));
        }
        else i++;
    }
    
    answer = stoi(s);
    return answer;
}
```
```cpp title='정규식을 사용한 방법, 생각보다 느림'
#include <string>
#include <vector>
#include <regex>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> str = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    regex r;
    int i = 0;
    for(int i = 0; i < str.size(); i++)
    {
        r = str[i];
        s = regex_replace(s, r, to_string(i));
    }
    
    answer = stoi(s);
    return answer;
}
```