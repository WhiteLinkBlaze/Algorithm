# [문자 개수 세기](https://school.programmers.co.kr/learn/courses/30/lessons/181902)
## 풀이
문자열 내에 문자가 얼마나 나오는지 횟수를 세는 문제임
+ 52칸의 배열(영문자 대소문자 합 총 52자)을 준비한다.
+ A가 ascii 기준 65
+ a가 ascii 기준 97
+ 0 부터 25번까지 대문자가 카운트 되고, 26부터 51까지 소문자들이 카운트 되도록 구성했다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer = vector<int>(52,0);
    int start = 'A';
    for(auto el : my_string)
    {
        if(el >= 'a')
        {
            start = 'a' - 26;
        }
        else
        {
            start = 'A';
        }
        answer[el - start]++;
        
        
    }
    return answer;
}
```
