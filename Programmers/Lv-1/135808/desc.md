# [과일 장수](https://school.programmers.co.kr/learn/courses/30/lessons/135808)
## 풀이
- 한 상자에 사과를 m개씩 담아 포장합니다.
- 상자에 담긴 사과 중 가장 낮은 점수가 p (1 ≤ p ≤ k)점인 경우, 사과 한 상자의 가격은 p * m 입니다.
- (최저 사과 점수) x (한 상자에 담긴 사과 개수) x (상자의 개수)

+ score를 내림차순 정렬합니다.
+ 맨 뒤에서 부터 m개씩 구분해서 내려오는데
	+ `i-m`에 위치한 값이 그 구간의 가장 작은 값이므로 `score[i-m]*m`을 결과에 더합니다.

## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end());
    for(int i = score.size(); i-m >= 0; i-=m)
    {
        answer += (score[i-m] * m);
    }
    return answer;
}
```
