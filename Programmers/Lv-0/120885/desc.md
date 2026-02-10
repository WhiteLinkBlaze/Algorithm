# [이진수 더하기](https://school.programmers.co.kr/learn/courses/30/lessons/120885)
## 풀이
이전에 풀었던 [[두 수의 합]]과 비슷한 문제이다. [두 수의 합](https://school.programmers.co.kr/learn/courses/30/lessons/181846)

10진수에서 했던 걸 2로 바꾸고, 이번에는 자릿수를 채우지 않는 방법을 사용해서 수정했다.

```cpp
while(i >= 0 || j>= 0 || carry)
    {
        int sum = carry;
        //처리할 bin1이 있으면 bin1의 값 추가
        if(i>=0)sum+=bin1[i--]-'0';
        //처리할 bin2가 있으면 bin2의 값 추가
        if(j>=0)sum+=bin2[j--]-'0';
        //이진수이기 때문에 %2로 나머지 값에 '0'을 더해 문자로 바꾸고 answer를 구성
        answer.push_back((sum%2)+'0');
        //올림 처리할 값
        carry = sum/2;
    }
```
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int carry = 0;
    int i = bin1.size() - 1;
    int j = bin2.size() - 1;
    
    while(i >= 0 || j>= 0 || carry)
    {
        int sum = carry;
        if(i>=0)sum+=bin1[i--]-'0';
        if(j>=0)sum+=bin2[j--]-'0';
        
        answer.push_back((sum%2)+'0');
        carry = sum/2;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
```
