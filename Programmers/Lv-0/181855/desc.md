# [문자열 묶기](https://school.programmers.co.kr/learn/courses/30/lessons/181855)
## 풀이
`strArr`의 원소들을 길이가 같은 문자열들끼리 그룹으로 묶었을 때 가장 개수가 많은 그룹의 크기를 반환하는 문제임

+ 배열의 개수 정보를 받아서 배열`arr[31] ={0,};`안에 카운팅 한다.
+ 배열내의 값들을 순회하여, 가장 큰 값을 반환한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    int arr[31] = {0,};
    int max =-1;
    for(string str : strArr)arr[str.length()]++;
    for(int i=1;i<31;i++)if(arr[i]>max)max = arr[i];
    answer = max;
    return answer;
}
```
