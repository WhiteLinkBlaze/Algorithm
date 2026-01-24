# [문자열 밀기](https://school.programmers.co.kr/learn/courses/30/lessons/120921)
## 풀이
+ 문자열을 민다는 것은 밀었지만 시작지점만 동일하다면 문자열 길이 만큼 탐색하면 결국은 같은 문자열이라는 것이다.
+ 먼저 A의 시작 문자를 B에서 찾는다. (여러개 있을 수 있다.)
+ 시작 위치를 기반으로 문자열 길이만큼 탐색하여 B랑 비교한다. 전부 맞았다면 바로 반환한다.(최소한으로 민 횟수를 구하기 때문)

## 코드

```cpp
#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    bool check = false;
    vector<int> start;
    int answerStart =  0;
    int count = 0;
    
    int len = A.length(); //A와 B의 길이는 같고 수정될 일이 없음
    
    //시작 위치 고르기
    for(int i = 0; i < len; i++)
    {
        if(A[0] == B[i])
        {
            start.push_back(i);
        }
    }
    
    //시작 위치를 토대로 검사
    for(int startIndex : start)
    {
        count = 0;
        for(int i = 0; i < len; i++)
        {
            int index = (count+startIndex)%len;
            if(A[i] != B[index])
                break;
            count++;
        }
        if(count == len)
        {
            check = true;
            answerStart = startIndex;
            break;
        }
    }
    answer  = check ? answerStart :-1;
    return answer;
}
```