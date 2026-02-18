# [한 번만 등장한 문자](https://school.programmers.co.kr/learn/courses/30/lessons/120896)
## 풀이
한 번만 등장하는 문자를 사전 순으로 정렬한 문자열을 return하는 문제임

한 번만 등장하는 지 확인하고, 정렬한 문자열이라서 map 구조를 사용하기로 했다.
+ map은 key, value의 형태로 값을 저장하고, 정렬된 상태를 유지하기에 해당 문제를 풀기에 적합하다고 생각했다.
+ 등장하는 문자로 key의 형태로 집어넣고 값을 1 증가시킨다.
+ 모든 문자를 처리했다면 마지막으로 map의 원소들을 검사해서 값이 1인 key값만 분리해서 answer에 포함시켜 반환한다.
## 코드
```cpp
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char,int> m;
    for(char ch : s)
    {
        m[ch]++;
    }
    for(auto v : m)
    {
        if(v.second == 1)answer += v.first;
    }
    return answer;
}
```
```cpp title='이렇게 안 해도 됨'
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char,int> m;
    for(char ch : s)
    {
        if(m.find(ch) == m.end())
            m.insert(make_pair(ch,1));
        else m[ch]++;
    }
    for(auto iter = m.begin(); iter != m.end(); iter++)
    {
        if(iter->second == 1)answer += iter->first;
    }
    return answer;
}
```