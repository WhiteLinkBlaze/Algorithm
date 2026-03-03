# [2016년](https://school.programmers.co.kr/learn/courses/30/lessons/12901)
## 풀이
일주일은 월요일 ~ 일요일을 반복한다. 
+ 1월 1일은 금요일이므로 0번 인덱스가 목요일인 요일 배열을 만든다.
+ 알고 싶을 날짜의 일수를 계산하여 나머지 연산 7을 한다.

### ctime 헤더를 쓰는 방법

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int DiM[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    string days[7] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    int sum = 0;
    for(int i=1; i < a; i++)sum += DiM[i];
    sum+=b;
    sum = sum%7;
    answer = days[sum];
    return answer;
}
```
```cpp title='ctime header'
#include <string>
#include <vector>
#include <ctime>
using namespace std;

string solution(int a, int b) {
    string answer;
    std::tm time_in = { 0 };
    time_in.tm_year = 2016 - 1900; 
    time_in.tm_mon = a - 1;
    time_in.tm_mday = b;

    std::mktime(&time_in);

    const char* days[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    answer = days[time_in.tm_wday];
    return answer;
}
```
