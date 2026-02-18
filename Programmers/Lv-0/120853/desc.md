# [컨트롤 제트](https://school.programmers.co.kr/learn/courses/30/lessons/120853)
## 풀이
문자열의 적힌 숫자의 합을 구하는데 'Z'가 있다면 이전의 값을 제외한 합을 구해야한다.

+ 공백을 기준으로 문자열을 split 한다.
+ split된 배열을 하나씩 순회하며, Z인지 확인한다.
	+ Z가 아니라면 answer에 그대로 더하고, 이전 값에 해당 값을 기록한다.
	+ Z라면 이전 값을 answer에서 뺀다.
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

int solution(string s) {
    int answer = 0;
    int before_num = 0;
    vector<string> fomu = split(s,' ');
    for(int i=0;i<fomu.size();i++)
    {
        if(fomu[i].compare("Z") == 0)
            answer -= before_num;
        else
        {
            answer += stoi(fomu[i]);
            before_num = stoi(fomu[i]);
        }
    }
    return answer;
}
```
