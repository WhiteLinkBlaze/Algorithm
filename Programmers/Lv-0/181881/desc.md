# [조건에 맞게 수열 변환하기 2](https://school.programmers.co.kr/learn/courses/30/lessons/181881)
## 풀이
`arr`의 각 원소에 대해 값이 50보다 크거나 같은 짝수라면 2로 나누고, 50보다 작은 홀수라면 2를 곱하고 다시 1을 더한다.

이러한 작업을 x번 반복한 결과인 배열 `arr(x)`가 `arr(x+1)`과 같아지는 가장 작은 x를 구하시오.

문제의 작업은 종료하는 순간이 존재한다.
+ 50 이상인데 홀수인 경우와 50미만인데 짝수인 경우 해당 작업의 대상이 되지 않는다.

그렇다면 각 요소에 대해 해당 작업의 대상이 되지 않을 때까지 작업을 처리하면 된다.

`arr`원소의 값의 범위는

$$
1 \leq \text{arr의 원소의 값} \leq 100
$$

`arr`원소의 작업 종료 후 나올 수 있는 최댓값은 49 * 2 + 1 = 99이다. 즉 원소의 범위는 작업을 처리 중인 과정에서도 1~100까지 유지된다. 넓은 범위는 아니기 때문에 메모이제이션을 사용하여 동일한 구간에 도달하는 숫자들을 더 빠르게 처리할 수 있도록 했다.

구간에 도달한 횟수를 기록하기 위한 `memo[101]`을 0으로 초기화 후 1~100까지 작업 처리 시작부터 작업 처리 대상에서 제외 될 때까지의 횟수를 기록한다. 
+ 작업 처리 제외 대상 조건
    + 50 이상인데 홀수인 경우
    + 50 미만인데 짝수인 경우
+ 작업 탈출 조건
    + 작업 처리 제외 대상이 됨
    + 이전에 처리를 끝낸 숫자임
+ 작업을 탈출하고 `memo[]`에 `count`를 기록함

위 조건들을 코드로 구현하고, `arr`내에 있는 요소들을 `memo[]`에서 찾아내 횟수가 가장 많은 것을 answer에 저장하고 반환한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int max = 0;
    //init memo
    int memo[101] = {0,};
    for(int i = 1; i <= 100; i++)
    {
        int dummy = i;
        int count = 0;
        while(!((dummy >= 50 && dummy%2 == 1) || (dummy<50 && dummy%2==0)))
        {
            if(memo[dummy] > 0) 
            {
                memo[i] = memo[dummy] + count;
                break;
            }
            if(dummy >= 50 && dummy % 2 == 0) dummy/=2;
            else if(dummy < 50 && dummy % 2 == 1) dummy = dummy*2+1;
            count++;
        }
        if(memo[i] == 0) memo[i] = count;
    }
    //process
    for(int i=0; i<arr.size(); i++)
    {
        if(memo[arr[i]] > max) max = memo[arr[i]];
    }
    answer = max;
    return answer;
}
```
