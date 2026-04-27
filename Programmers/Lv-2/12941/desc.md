# [최솟값 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/12941)
## 풀이
배열 두 개에서 각각 한 개의 숫자를 뽑아서 두 수를 곱하는데, 곱한 값을 누적하여 더하여 최종적으로 누적된 값이 최소가 되도록 만드는 것이 목표

1. 두 배열 모두 정렬한다.
2. 한 쪽 배열에서 최솟값을, 한 쪽 배열에서 최댓값을 가져와 곱한다.
3. 결과를 answer에 누적한다.
## 코드
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i=0; i < A.size(); i++)
    {
        answer += A[i]*B[B.size()-1-i];
    }

    return answer;
}
```
