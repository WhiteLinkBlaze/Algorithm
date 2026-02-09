# [공 던지기](https://school.programmers.co.kr/learn/courses/30/lessons/120843)
## 풀이
K번째 공을 던지는 사람이 번호가 무엇인가를 묻는 문제임
+ 던질 사람 cur
+ 배열을 탐색하는데 cur 친구가 던질 때 자신의 위치 +2한 위치의 있는 친구에게 던진다. -> (cur+2)%numbers.size()
+ 그러면 cur의 친구 변경 cur+=2
+ count를 올려서 던진 횟수 계산후 반복을 나가면 answer에는 마지막으로 던진 사람의 번호가 기록됨

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    int count = 1;
    int cur = 0;
    while(count < k)
    {
        answer = numbers[(cur+2)%numbers.size()];
        cur+=2;
        count++;
    }
    return answer;
}
```

