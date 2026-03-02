# [예산](https://school.programmers.co.kr/learn/courses/30/lessons/12982)
## 풀이
그리디 문제임
> 부서별로 신청한 금액이 들어있는 배열 d와 예산 budget이 매개변수로 주어질 때, 최대 몇 개의 부서에 물품을 지원할 수 있는지 return 하도록 solution 함수를 완성해주세요.

`[1,3,2,5,4]`가 주어지면 budget 9로는 최대 3개의 부서를 지원할 수 있음
+ 1, 3 ,5 원 신청한 부서들을 지원
+ 2, 3, 4 원 신청한 부서들을 지원

아이디어는 이렇다.
+ 값이 작은 예산 신청들을 처리하면 많이 처리하게 되지 않을까?

+ 정렬한다. (값이 작은 예산 신청을 앞으로)
+ 예산에서 값을 뺄 수 있으면 빼고, 처리한 부서의 수(`answer`)를 늘림
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int left_budget = budget;
    sort(d.begin(),d.end());
    for(int num : d)
    {
        if(num <= left_budget)
        {
            answer+=1;
            left_budget -= num;
        }
    }
    return answer;
}
```
