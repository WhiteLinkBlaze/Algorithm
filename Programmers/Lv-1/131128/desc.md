# [숫자 짝꿍](https://school.programmers.co.kr/learn/courses/30/lessons/131128)
## 풀이
숫자 X와 숫자 Y의 구성요소 중 같은 것들을 모아놓은 것이 숫자 짝꿍(중복 허용)
+ "12321" 과 "42531"은 "321"짝꿍을 가지는데 이를 짝꿍으로 만들 수 있는 큰 수를 찾는다.

숫자 X와 숫자 Y는 상당히 큰 정수이므로 문자열로 처리한다.
+ 각 숫자의 구성요소를 센다. (`memo[10], result[10]`)
+ 겹치는 구성요소(`result[10]`)으로 역순(9->0)으로 순회하여 숫자를 만든다.
+ 구성요소 중 숫자 0만 여러번 들어가 있었다면 0은 1회만 들어가도록 구성한다.
+ 겹치는 게 없었다면 -1을 기록하고 반환
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int memo[10] = {0,};
    int result[10] = {0,};
    long long num = 0;
    for(char n : X)
    {
        memo[n-'0']++;
    }
    for(char n : Y)
    {
        if(memo[n-'0']-->0)result[n-'0']++;
    }
    for(int i=9;i>=0;i--)
    {
        while(result[i]-->0)
        {
            if(answer.length() != 0 && answer[0] == '0')break;
            answer.push_back(i+'0');
        }
    }
    if(answer.length() == 0)answer = "-1";
    
    return answer;
}
```