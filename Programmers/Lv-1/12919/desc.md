# [서울에서 김서방 찾기](https://school.programmers.co.kr/learn/courses/30/lessons/12919)
## 풀이
```cpp title='C++20부터 사용 가능'
std::format("{} {}!", "Hello", "world", "something"); // OK, produces "Hello world!"
```
+ `vector`에서 `find`를 사용하여 반환하는 값은 해당 원소가 존재하는 `iterator`를 반환하므로 시작 반환자인 `begin()`을 빼서 해당 인덱스를 구할 수 있다.
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    int x = 0;
    x = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    answer+=to_string(x);
    answer+="에 있다";
    return answer;
}
```
