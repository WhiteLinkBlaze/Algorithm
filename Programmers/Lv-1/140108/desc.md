# [문자열 나누기](https://school.programmers.co.kr/learn/courses/30/lessons/140108)
## 풀이
구현 문제
- 먼저 첫 글자를 읽습니다. 이 글자를 x라고 합시다.
- 이 문자열을 처음부터 탐색하면서, x와 x가 아닌 다른 글자들이 나온 횟수를 각각 센다.
+ 처음으로 두 횟수가 같아지는 순간 멈추고, 지금까지 읽은 문자열을 분리합니다.
여기서 분리한 횟수를 카운트해서 반환한다.
+ same과 diff가 같으면 x를 현재 위치의 문자로 교환한다. 
	+ 그리고 answer증가
+ 이후 x랑 s의 i번째 요소와 비교하여 다시 카운트를 시작한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int same_cnt = 0;
    int diff_cnt = 0;
    char x;
    for(int i = 0; i < s.length(); i++)
    {
        if(same_cnt == diff_cnt)
        {
            x = s[i];
            same_cnt = 0;
            diff_cnt = 0;
            answer++;
        }
        if(x == s[i])same_cnt++;
        else diff_cnt++;
    }
    
    return answer;
}
```