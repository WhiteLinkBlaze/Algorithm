# [문자열 여러 번 뒤집기](https://school.programmers.co.kr/learn/courses/30/lessons/181913)
## 풀이
queries에 있는 값을 이용해 my_string의 문자열의 내부 요소들을 조작한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";
    answer = my_string;
    for(auto query : queries)
    {
        int s = query[0];
        int e = query[1];
        for(int i = 0; i <= (e-s)/2; i++)
        {
            swap(answer[s+i], answer[e-i]);
        }
    }
    return answer;
}
```
