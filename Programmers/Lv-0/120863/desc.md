# [다항식 더하기](https://school.programmers.co.kr/learn/courses/30/lessons/120863)
## 풀이
+ 조건에 제공되는 문자열은 x, +, 숫자로만 구성되고, +3x + 이런식으로는 구성되지 않는다고 한다.
+ 제공받은 문자열을 공백을 기준으로 분할한다.
+ 맨 뒷자리가 x인지 확인한다.
	+ 맞다면 첫 자리가 x인지 확인한다.
	+ x의 개수를 저장하는 변수 x에 숫자를 기록한다. (첫 자리가 x였다면 1)
+ + 인 경우 넘어간다
+ 숫자인 경우 해당 문자를 숫자로 변환하여 number에 더한다.
+ 반환하려는 문자열을 구성할 때 주의할 것은 

1. x
2. 2x + 3
3. 3

+ 위와 같은 형태로 구성해야 한다는 것이다.
+ x의 숫자가 1이면 1은 기록하지 않는다.
+ x 이후에 숫자가 나와야 + 가 붙는다.
+ x가 없어도 number가 있다면 number를 기록한다.
## 코드

```cpp
#include <string>
#include <vector>

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

string solution(string polynomial) {
    string answer = "";
    int x = 0;
    int number = 0;
    vector<string> str = split(polynomial, ' ');
    for(int i=0; i<str.size();i++)
    {
        char lastWord = str[i][str[i].length()-1];
        if(lastWord == 'x')
        {
            //stoi 함수 사용시 해당 문자열에 숫자가 없으면 core dump 일어남
            x += str[i][0] == 'x' ? 1 : stoi(str[i]);
        }
        else if(str[i].compare("+") == 0)
            continue;
        else
            number += stoi(str[i]);
    }
    
    string xString = x > 1 ? to_string(x)+"x" : "x";
    string numString = to_string(number);
    
    if(x!=0)
        answer+=xString;
    if(answer.length() != 0 && number != 0)
        answer+=" + ";
    if(number != 0) 
        answer += numString;
    
    return answer;
}
```