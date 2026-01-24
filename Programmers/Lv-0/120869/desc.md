# [외계어 사전](https://school.programmers.co.kr/learn/courses/30/lessons/120869)
## 풀이
+ dic에서 단어를 받아서 spell에 있는 문자들로 검색을 한다.
+ string.find()함수는 찾았을 경우 위치를 반환하고, 없는 경우 string::npos를 반환한다.
+ 다 검사해서 하나라도 모두 있었다면 1 을 반환한다.

## 코드

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    for(string elementDic : dic)
    {
        int count = 0;
        for(string spellTxt: spell)
        {
            //사전의 단어에 원하는 단어가 있는가
            if(elementDic.find(spellTxt) != string::npos)
                count++;
            else
                break;
        }
        //단어가 전부 들어가 있었는가
        if(count == spell.size())
        {
            answer = 1;
            break;
        }
    }
    
    return answer;
}
```