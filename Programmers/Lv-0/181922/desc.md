# [수열과 구간 쿼리 4](https://school.programmers.co.kr/learn/courses/30/lessons/181922)
## 풀이
queries의 담긴 요소들을 하나씩 처리한다.
+ s부터 e사이에 있는 i가 k의 배수인 경우 `arr[i]`에 1을 추가한다.
+ 모든 요소를 처리한 후 answer에 arr을 넘긴다.

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(vector<int> query : queries)
    {
        int s = query[0];
        int e = query[1];
        int k = query[2];
        
        for(int i = s; i <= e; i++)
        {
            if(i % k == 0) arr[i]++;
        }
    }
    answer = arr;
    return answer;
}
```