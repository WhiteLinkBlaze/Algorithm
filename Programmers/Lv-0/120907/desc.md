# [OX퀴즈](https://school.programmers.co.kr/learn/courses/30/lessons/120907)
## 풀이
+ 음수의 경우 숫자와 붙어서 제공되므로 공백을 기준으로 문자열을 분할했다.
+ 분할 하게 되면 숫자, 연산자, 숫자, 등호(=), 숫자 식으로 분할된다.
+ 연산자 기준으로 식을 구성하여 연산 결과와 마지막 숫자와 비교하여 결과(O,X)를 저장한다.

## 코드
```cpp
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> split(string sentence, char deli)
{
    vector<string> dummy;
    int base=0,next=0;
    while((next = sentence.find(deli,base))!=string::npos)
    {
        int len = next - base;
        dummy.push_back(sentence.substr(base,len));
        base = next + 1;
    }
    dummy.push_back(sentence.substr(base,next-base));
    return dummy;
    
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    int result = 0;
    for(string oper: quiz) 
    {
        string curAnswer = "";
        vector<string> operFom = split(oper,' ');
        switch(operFom[1][0])
        {
            case '+':
                result = stoi(operFom[0]) + stoi(operFom[2]);
                break;
            case '-':
                result = stoi(operFom[0]) - stoi(operFom[2]);
                break;
        }
        curAnswer = result == stoi(operFom[operFom.size()-1])?"O":"X";
        answer.push_back(curAnswer);
    }
    return answer;
}
```