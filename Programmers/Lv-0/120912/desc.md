# [7의 개수](https://school.programmers.co.kr/learn/courses/30/lessons/120912)
## 풀이
배열 내에 숫자 7이 몇 개 들어있는지 세는 문제임

배열 내에는 int형 값으로 저장되어 있으므로 문자로 바꾸거나, 숫자 형태 그대로 쓰는 등의 방법이 있다. 
+ 문자형으로 바꾼다.
+ 문자 내에서 7을 계속해서 찾고 찾으면 `answer++;`
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(int num : array)
    {
        string str = to_string(num);
        int base = 0, next=0;
        
        while((next = str.find('7',base))!=string::npos)
        {
            base = next+1;
            answer++;
        }
    }
    return answer;
}
```