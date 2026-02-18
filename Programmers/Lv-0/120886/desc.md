# [A로 B 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/120886)
## 풀이
before와 after가 문자의 순서를 바꾸면 서로 동일한지 판별하는 문제임

before의 구성 요소의 개수가 after의 구성 요소의 개수와 같으면 서로 동일하다.
+ map을 활용하여 각 문자마다의 개수 측정
+ 두 개의 구성 요소 정보를 한 map에 집어 넣는다.
	+ 동일한 구성 요소 정보를 넣었다면 같은 값이 2회 이상 들어가게 된다. 
+ 모두 처리한 후 map의 요소중 하나라도 2의 배수가 아니라면 동일하지 않으므로 0을 반환
+ 모두 2의 배수라면 1을 반환한다.
## 코드
```cpp
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string before, string after) {
    int answer = 1;
    map<char, int> m;
    for(char ch : before)
    {
        m[ch]++;
    }
    for(char ch : after)
    {
        m[ch]++;
    }
    for(auto iter = m.begin(); iter!=m.end();iter++)
    {
        if(iter->second%2 != 0) return answer = 0;
    }
        
    return answer;
}
```