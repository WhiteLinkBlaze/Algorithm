# [가장 가까운 같은 글자](https://school.programmers.co.kr/learn/courses/30/lessons/142086)
## 풀이
+ 최근 위치를 기록했다면 현재 위치 - map의 기록된 위치를 계산하여 answer에 추가합니다.
+ 최근 위치를 기록하지 않았다면 map에 없으므로 -1을 `answer`에 추가합니다.
+ 가장 최근 위치를 map에 기록합니다.
## 코드
```cpp
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> m;
    char ch ;
    for(int i = 0; i < s.length(); i++)
    {
        ch = s[i];
        if(m.find(ch) != m.end()) 
            answer.push_back( i - m[ch]);
        else 
            answer.push_back(-1);
        m[ch] = i;
    }
    return answer;
}
```
