# [푸드 파이트 대회](https://school.programmers.co.kr/learn/courses/30/lessons/134240)
대회의 공정성을 위해 두 선수가 먹는 음식의 종류와 양이 같아야 하며, 음식을 먹는 순서도 같아야 합니다. 또한, 이번 대회부터는 칼로리가 낮은 음식을 먼저 먹을 수 있게 배치하여 선수들이 음식을 더 잘 먹을 수 있게 하려고 합니다.
## 풀이
요약하자면 음식의 개수가 짝수여야 모든 선수가 공정하게 먹을 수 있는데 짝수가 아닌 음식들이 존재한다는 것 이를 고려하여 음식을 순서대로 나열한 문자열을 만들라는 것이 문제의 요지임
+ i번째 음식이 2로 나눴을 때의 개수 만큼 문자열에 적용시킵니다.
+ 정답으로 나와야 하는 문자열은 `food_line` + `water` + `reverse_food_line`의 형태입니다.
+ 따라서 아래와 같이 적용한다.
```cpp
answer = food_line + "0";
reverse(food_line.begin(), food_line.end());
answer += food_line;
```
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string food_line = "";
    for(int i=1; i < food.size(); i++)
    {
        for(int j=1; j < food[i]; j+=2)
        {
            food_line += to_string(i);
        }
    }
    
    answer = food_line + "0";
    reverse(food_line.begin(), food_line.end());
    answer += food_line;
    return answer;
}
```
