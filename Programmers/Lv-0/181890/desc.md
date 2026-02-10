# [왼쪽 오른쪽](https://school.programmers.co.kr/learn/courses/30/lessons/181890)
## 풀이
1. vector 내에서 `l` or `r`을 찾는다.
2. 찾은 위치를 서로 비교한다.
    1. r의 위치가 작다 = r이 먼저 나온다.
    2. l의 위치가 작다 = l이 먼저 나온다.
    3. 같거나 없다 = 빈 배열 반환
3. 찾은 위치를 기반으로 배열을 잘라서 answer에 저장하고 반환한다. (assign 함수 사용)

## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    auto it_l = find(str_list.begin(), str_list.end(),"l");
    auto it_r = find(str_list.begin(), str_list.end(), "r");
    
    if(it_l > it_r) answer.assign(it_r+1, str_list.end());
    else if(it_l < it_r) answer.assign(str_list.begin(),it_l);
    return answer;
}
```