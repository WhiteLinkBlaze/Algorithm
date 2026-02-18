# [k의 개수](https://school.programmers.co.kr/learn/courses/30/lessons/120887)
## 풀이
i부터 j까지의 수 중에서 k라는 숫자가 몇 개 등장하는지 카운팅하는 문제임
+ i 부터 j 까지 순회
+ i 값을 문자열로 치환
+ 해당 문자열을 순회하며 문자가 k라는 문자라면 있다면 `answer++;`

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    for(;i<=j;i++)
    {
        string str = to_string(i);
        for(char ch : str)if(ch == k + '0')answer++;
    }
    return answer;
}
```
