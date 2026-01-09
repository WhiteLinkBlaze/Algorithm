# [삼각형의 완성조건 (1)](https://school.programmers.co.kr/learn/courses/30/lessons/120889)
## 풀이
1. sides 내에서 큰 수의 index를 구한다. maxIndex
2. 가장 큰 수 를 제외한 나머지 수들의 합(==sumOther==)을 구한다.
3. sumOther 와 sides\[maxIndex]의 값을 비교하여 sumOther이 크다면 1 작다면 2를 answer에 저장한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
int maxInVector(vector<int> list, int start, int end)
{
    int max = -1;
    int result = 0;
    for(int i = start; i < end; i++)
    {
        if(max < list[i])
        {
            result = i;
            max = list[i];
        }
    }
    return result;
}
int solution(vector<int> sides) {
    int answer = 0;
    int maxIndex = maxInVector(sides, 0, 3);
    int sumOther = 0;
    for(int i = 0; i < sides.size(); i++)
    {
        if(i == maxIndex)continue;
        sumOther += sides[i];
    }
    answer = sumOther > sides[maxIndex] ? 1 : 2;
    return answer;
}
```