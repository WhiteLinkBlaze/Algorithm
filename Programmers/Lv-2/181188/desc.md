# [요격 시스템](https://school.programmers.co.kr/learn/courses/30/lessons/181188)
## 풀이
> 그리디는 간단하게 생각하자
```txt
[[1, 3], [5, 13], [7, 8], [9, 10]] > 정답은 3

//정렬 후
[[1, 3], [7, 8], [9, 10], [5, 13]]
```
+ 종료 위치를 기준으로 오름차순 정렬한다.
+ 이렇게해서 end를 기준으로 새로 들어온 start가 end보다 작다면 같은 포격 위치이다.
+ start가 end보다 크거나 같다면 새로 포격을 가해야하기 때문에 end를 start의 end로 갱신한다.

## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(),[](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });
    
    int end = -1;
    
    for(int i = 0; i < targets.size(); i++)
    {
        int start = targets[i][0];
        if(start >= end)
        {
            end = targets[i][1];
            answer++;
        }
    }
        
    return answer;
}
```
