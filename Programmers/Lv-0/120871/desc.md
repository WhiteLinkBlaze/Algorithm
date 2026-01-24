# [저주의 숫자 3](https://school.programmers.co.kr/learn/courses/30/lessons/120871)
## 풀이
+ 아쉬운 풀이 다음에 더 생각해볼 것
+ 1부터 숫자 3의 배수인지, 3이 들어가 있는 지를 구분하여 offset을 기록해서 찾아야한다.
+ 숫자를 만났을 때 해당 숫자+offset인데 3이 있는가?, 3의 배수인가? 둘 중 하나라도 맞는다면 offset이 증가한다.
+ 이렇게 차례대로 올려서 답을 구한다.

## 코드

```cpp
#include <string>
#include <vector>

using namespace std;

bool findThree(int n)
{
    string nString = to_string(n);
    if(nString.find('3') != string::npos)
        return true;
    return false;
}
int solution(int n) {
    int answer = 0;
    int offset = 0;
    
    for(int i = 1; i <= n; i++)
    {
        int result = i + offset;
        while(findThree(result) || result % 3 == 0)
        {
            offset++;
            result++;
        }
        answer = result;
    }
    return answer;
}
```