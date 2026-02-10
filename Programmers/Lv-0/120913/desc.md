# [잘라서 배열로 저장하기](https://school.programmers.co.kr/learn/courses/30/lessons/120913)
## 풀이
정해진 구간을 기반으로 문자열을 잘라서 저장하고 반환한다.

n씩 자른다 하면 i 부터 n 개까지 자르고 i는 i+n을 가리키도록 하면 된다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    for(int i=0; i<my_str.size(); i+=n)
    {
        answer.push_back(my_str.substr(i, n));
    }
    return answer;
}
```