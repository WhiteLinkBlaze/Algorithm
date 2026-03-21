# [덧칠하기](https://school.programmers.co.kr/learn/courses/30/lessons/161989)
## 풀이
주어지는 리스트의 첫 요소는 반드시 칠하게 될 요소임
+ 해당 요소부터 칠했다고 가정해서 어디까지 칠했는지를 기록한다. `painted`
+ 다음 요소를 참조했을 때 이미 칠한 부분인지 확인 `painted >= section[i]`
	+ 칠해야할 부분이면 `painted`를 갱신하고 answer++하면 된다.
## 코드
```cpp
#include <string>
#include <vector>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int painted = 0;
    for(int i = 0; i < section.size(); i++)
    {
        if(painted >= section[i])continue;
        painted = section[i]+m-1;
        answer++;
    }
    return answer;
}
```
