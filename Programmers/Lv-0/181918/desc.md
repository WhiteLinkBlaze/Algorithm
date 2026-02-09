# [배열 만들기 4](https://school.programmers.co.kr/learn/courses/30/lessons/181918)
## 풀이
변수 `i`를 만들어 초기값을 0으로 설정한 후 `i`가 `arr`의 길이보다 작으면 다음 작업을 반복합니다. ->`i = 0, i < arr.size(),  반복문 사용

- 만약 `stk`가 빈 배열이라면 `arr[i]`를 `stk`에 추가하고 `i`에 1을 더합니다.
- `stk`에 원소가 있고, `stk`의 마지막 원소가 `arr[i]`보다 작으면 `arr[i]`를 `stk`의 뒤에 추가하고 `i`에 1을 더합니다.
- `stk`에 원소가 있는데 `stk`의 마지막 원소가 `arr[i]`보다 크거나 같으면 `stk`의 마지막 원소를 `stk`에서 제거합니다.

문제를 그대로 코드로 바꾸었다.
+ 반복의 형태에 따라서 i의 증감을 주의할 것
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    for(int i = 0; i < arr.size(); i++)
    {
        if(stk.size() == 0)stk.push_back(arr[i]);
        else if(stk.back() < arr[i])stk.push_back(arr[i]);
        else 
        {
            stk.erase(stk.end()-1);
            i--;
        }
    }
    return stk;
}
```
