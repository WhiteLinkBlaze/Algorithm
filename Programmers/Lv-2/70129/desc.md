# [이진 변환 반복하기](https://school.programmers.co.kr/learn/courses/30/lessons/70129)
## 풀이
1. x의 모든 0을 제거함
2. x의 길이를 c라고 하면, x를 "c를 2진법으로 표현한 문자열로 바꿈"
위의 1, 2를 주어진 문자열 s가 "1"이 될 때까지 계속해서 s에 이진 변환을 가할 것

위의 기능 중 모든 0을 제거하는 부분을 함수로 빼고 결과로 반환하는 값을 개수로 바꾸었다.
+ 이렇게 나온 결과를 현재 문자열의 길이에서 제외하면 나머지는 0의 개수이다.
+ 그리고 현재 문자열을 결과로 받은 값의 이진 문자열로 바꾼다.
+ 그리고 이것을 반복한다.

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
int func(string s)
{
    vector<int> answer;
    for(int i=0; i<s.length(); i++) if(s[i] == '1')answer.push_back(s[i]);
    return answer.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int sum = 0;
    while(s.length() > 1)
    {
        int after = func(s);
        int before = s.length() - after;
        s.clear();
        while(after > 0)
        {
            s += '0' + after%2;
            after /= 2;
        }
        cnt++;
        sum += before;
    }
    answer = {cnt, sum};
    return answer;
}
```
