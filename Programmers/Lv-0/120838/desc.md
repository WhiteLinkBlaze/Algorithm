# [모스부호 (1)](https://school.programmers.co.kr/learn/courses/30/lessons/120838)
## 풀이
주어지는 모스부호를 영문자로 바꾸는 문제임
+ 모스부호는 공백으로 분리됨 (공백을 기준으로 split)
	+ stringstream을 통해 공백을 기준으로 분리
+ 스플릿한 내용을 문자로 치환하여 `answer`에 저장
	+ 치환이 용이하도록 map을 이용하여 모스부호를 문자와 연결
+ answer 반환
```cpp title='C++, map에 하드코딩 방법'
map<string,char> morse = {
        {".-", 'a'},   {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, 
        {".", 'e'},    {"..-.", 'f'}, {"--.", 'g'},  {"....", 'h'}, 
        {"..", 'i'},   {".---", 'j'}, {"-.-", 'k'},  {".-..", 'l'},
        {"--", 'm'},   {"-.", 'n'},   {"---", 'o'},  {".--.", 'p'}, 
        {"--.-", 'q'}, {".-.", 'r'},  {"...", 's'},  {"-", 't'},
        {"..-", 'u'},  {"...-", 'v'}, {".--", 'w'},  {"-..-", 'x'},
        {"-.--", 'y'}, {"--..", 'z'}
    };
```
## 코드
```cpp
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

string solution(string letter) {
    string answer = "";
    map<string,char> morse = {
        {".-", 'a'},   {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, 
        {".", 'e'},    {"..-.", 'f'}, {"--.", 'g'},  {"....", 'h'}, 
        {"..", 'i'},   {".---", 'j'}, {"-.-", 'k'},  {".-..", 'l'},
        {"--", 'm'},   {"-.", 'n'},   {"---", 'o'},  {".--.", 'p'}, 
        {"--.-", 'q'}, {".-.", 'r'},  {"...", 's'},  {"-", 't'},
        {"..-", 'u'},  {"...-", 'v'}, {".--", 'w'},  {"-..-", 'x'},
        {"-.--", 'y'}, {"--..", 'z'}
    };
    stringstream ss;
    ss.str(letter);
    string str;
    while(ss>>str)
    {
        answer+=morse[str];
    }
    return answer;
}
```