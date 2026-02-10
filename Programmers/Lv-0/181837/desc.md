# [커피 심부름](https://school.programmers.co.kr/learn/courses/30/lessons/181837)
## 풀이
order에 요소에 맞는 가격 값을 answer에 더해서 반환한다.
+ cafelatte면 5000
+ 그 외 4500

코드는 americano랑 anything이랑 같이 써서 분할할 필요가 없지만 분할하는게 구분하기 쉽고 추후에 비슷한 문제에서 사용하기 편하게 하려고 구분했다.
## 코드
```cpp
#include <string>
#include <vector>
using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    for(string menu: order)
    {
        if(menu.find("cafelatte") != string::npos)
            answer+=5000;
        else if(menu.find("americano")!= string::npos)
            answer+=4500;
        else if(menu.find("anything")!= string::npos)
            answer+=4500;
    }
    return answer;
}
```
