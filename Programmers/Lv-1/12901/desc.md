# [2016년](https://school.programmers.co.kr/learn/courses/30/lessons/12901)
## 풀이
일주일은 월요일 ~ 일요일을 반복한다. 
+ 1월 1일은 금요일이므로 0번 인덱스가 목요일인 요일 배열을 만든다.
+ 알고 싶을 날짜의 일수를 계산하여 나머지 연산 7을 한다.

### ctime
std::tm의 연, 월, 일을 채워주면 나머지를 mktime이 채워준다.
#### [struct tm](https://cplusplus.com/reference/ctime/tm/)
| Member   | Type  | Meaning                   | Range   |
| -------- | ----- | ------------------------- | ------- |
| tm_sec   | `int` | seconds after the minute  | `0-61*` |
| tm_min   | `int` | minutes after the hour    | `0-59`  |
| tm_hour  | `int` | hours since midnight      | `0-23`  |
| tm_mday  | `int` | day of the month          | `1-31`  |
| tm_mon   | `int` | months since January      | `0-11`  |
| tm_year  | `int` | years since 1900          |         |
| tm_wday  | `int` | days since Sunday         | `0-6`   |
| tm_yday  | `int` | days since January 1      | `0-365` |
| tm_isdst | `int` | Daylight Saving Time flag |         |
#### mktime
```cpp
time_t mktime (struct tm * timeptr);
```
**매개변수 (`struct tm * timeptr`)**: 날짜와 시간 구성 요소(년, 월, 일, 시, 분, 초 등)가 담긴 구조체의 포인터

**반환값 (`time_t`)**:
- 성공 시: 1970년 1월 1일 00:00:00(UTC)부터 경과된 초(Epoch time)를 반환
- 실패 시: 해당 날짜를 표현할 수 없으면 `-1`을 반환
```cpp
#include <ctime>
int main()
{
	std::tm time_in = { 0 }; // 날짜 구성요소를 가진 구조체
	// 구조체를 설정
	time_in.tm_year = 2016 - 1900; 
	time_in.tm_mon = a - 1; // 0부터 11까지의 값
	time_in.tm_mday = b;
	//localtime으로 변환
	std::mktime(&time_in);
	return 0;
}
```
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
