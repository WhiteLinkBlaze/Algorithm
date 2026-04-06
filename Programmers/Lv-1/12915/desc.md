# [문자열 내 마음대로 정렬하기](https://school.programmers.co.kr/learn/courses/30/lessons/12915)
## 풀이
+ 특정 인덱스의 순서로 정렬을 한다.
+ 특정 인덱스의 순서가 동일하다면, 해당 문자열의 사전 순으로 정렬한다.
+ 정렬하는 기준을 작성하는 문제이다.
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int idx = 0;
int comp(string a, string b)
{
    if(a[idx] == b[idx])
    {
        return a < b;
    }
    return a[idx] < b[idx];
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    idx = n;
    sort(answer.begin(), answer.end(), comp);
    return answer;
}
```
```cpp title='람다식 풀이'
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    sort(answer.begin(), answer.end(), [n](auto a, auto b)
         {return a[n] == b[n] ? a < b : a[n] < b[n];});
    return answer;
}
```