# [문자열 정렬하기](https://school.programmers.co.kr/learn/courses/30/lessons/120850)
## 풀이
1. 추출할 문자 중 숫자는 0 ~ 9 사이만 존재하므로 10칸 짜리 list를 먼저 구성하고 0으로 초기화 한다.
2. 문자열에서 숫자를 추출한다.
3. 해당 숫자를 list에 개수를 기록한다.
4. list를 탐색하면서 기록한 개수만큼 answer에 저장한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    vector<int> list = vector<int>(10,0);
    //extract number
    for(int i = 0; i < my_string.length(); i++)
    {
        if(my_string[i] - '0' < 10 && my_string[i] - '0' >= 0)
            list[my_string[i]-'0']++;
    }
    //insert number
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < list[i];j++) 
            answer.push_back(i);
    }
    return answer;
}
```