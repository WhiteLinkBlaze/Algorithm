# [올바른 괄호](https://school.programmers.co.kr/learn/courses/30/lessons/12909)
## 풀이
괄호가 바르게 짝지어졌는지 확인하는 코드
+ 스택에 쌓는데 "(" 이것만 쌓는다.
+ ")"를 만나면 스택이 비어있지 않고, "(" 이게 위에 있다면 스택에서 꺼내고 넘어간다.
	+ 위 조건에 맞지 않는다면 바르게 짝지어지지 않으므로 탈출한다.
+ 스택이 비어있고 answer가 true여야 반환값이 true이다.
정답이 아닌것
+ "(" 이거 하나만 주어지는 것도 정답이 아니다.
## 코드
```cpp
#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for(char ch : s)
    {
        if(ch == '(') st.push(ch);
        else
        {
            if(!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else 
            {
                answer = false;
                break;
            }
        }
    }
    answer = st.empty() && answer;

    return answer;
}
```
