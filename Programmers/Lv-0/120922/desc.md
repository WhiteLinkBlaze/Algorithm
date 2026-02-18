# [종이 자르기](https://school.programmers.co.kr/learn/courses/30/lessons/120922)
## 풀이
가로, 세로 2, 5 종이는 가로로 1, 5의 종이를 만든다면 1회 잘라야하고, 1, 5의 종이를 1, 1의 종이를 만든다면 2 * 4회 잘라야하므로 결과는 8회이다. 이를 수식으로 나타내면 다음과 같다.

$$
count = M - 1 + M \times(N-1)
$$

$$
count = M\times N - 1
$$

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    int answer = 0;
    answer = M*N-1;
    return answer;
}
```