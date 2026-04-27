# [두 원 사이의 정수 쌍](https://school.programmers.co.kr/learn/courses/30/lessons/181187)
## 풀이
직교 좌표계에 중심이 원점인 원이기 때문에 4가지 구역중 하나만 개수를 계산하면 된다.
$$
x^2 + y^2 = r^2
$$
$$
y^2 = r^2-x^2
$$
+ 1사분면의 점들만을 카운트한다.
+ 점들의 개수를 세기 위해 시작 지점과 끝나는 지점을 구하여 end - start + 1을 한다면 안의 점들의 개수를 구할 수 있을 것이다.
+ y2와 y1은 끝나는 지점과 시작하는 지점이다.
	+ ${y2}^2 = {r2}^2 - x^2$ 일 것이다. 그런데 3.16 같은 경우 3부터 계산하도록 한다.(3도 개수에 포함된다.)
	+ ${y1}^2 = {r1}^2 - x^2$ 일 것이다. 그런데 1.414 같은 경우 2부터 계산하도록 한다.(2도 개수에 포함된다.)
		+ y1은 길이이기 때문에 0보다 작을 수 없다. (`max(y1, (long long) 0 )`)
+ 이렇게 뽑은 y2와 y1으로 해당 x좌표의 y좌표 개수를 계산한다. `answer += y2 - y1 + 1`
+ 이렇게 뽑은 answer는 1 사분면의 개수이므로 곱하기 4를 하여 나머지 구역들의 개수도 더해준다.
## 코드
```cpp
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long y2 = 0;
    long long y1 = 0;
    for(long long i = 1; i <=r2; i++)
    {
        y2 = floor(sqrt((long long)r2*r2 - i*i));
        y1 = ceil(sqrt((long long)r1*r1 - i*i));
        y1 = max(y1,(long long)0);
        answer += y2 - y1 + 1;
    }
    answer*=4;
    return answer;
}
```
