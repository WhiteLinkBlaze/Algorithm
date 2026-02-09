# [문자열 계산하기](https://school.programmers.co.kr/learn/courses/30/lessons/120902)
## 풀이
연산 기호가 복수개 나올 수 있음
+ 공백(' ')을 기준으로 요소들을 구분하여 배열을 구성함
+ 이렇게 구성된 배열은 0번째에 숫자 1번째에 연산 기호, 2번째에 숫자 이런식으로 반복된다. 연산기호는 홀수번째인 경우로 구별이 가능하다.
+ 탐색을 진행하여 짝수 번째(숫자 위치)인 경우 이전 위치(연산 기호)의 기호를 참조하여 answer에 연산한다. (+ 면 1을 곱하고, -면 -1을 곱하여 더하기 빼기를 만듬)

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
int solution(string my_string) {
    int answer = 0;
    vector<string> elements;
    int next;
    int cur = 0;
    //split
    while((next = my_string.find(' ',cur)) != string::npos)
    {
        elements.push_back(my_string.substr(cur,next-cur));
        cur = next+1;
    }
    elements.push_back(my_string.substr(cur));
    //operation
    answer = stoi(elements[0]);
    for(int i=2; i<elements.size(); i++)
    {
        if(i%2 == 0)
        {
            int oper = 1;
            oper = elements[i-1][0] == '+' ? 1:-1;
            answer += oper*(stoi(elements[i]));
        }
    }
    return abs(answer);
}
```
