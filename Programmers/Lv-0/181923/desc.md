# [수열과 구간 쿼리 2](https://school.programmers.co.kr/learn/courses/30/lessons/181923)
## 풀이
차례대로 해결하면된다.
+ s부터 e까지 탐색을 진행한다.
+ min 값보다 작고 목표하는 값보다 큰 값을 임시로 저장하여. answer에 더한다.
+ 임시로 저장하는 곳에 미리 -1을 저장해두어 갱신되지 않으면 -1을 저장하게 된다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(vector<int> query : queries)
    {
        int start = query[0];
        int end = query[1];
        int target = query[2];
        
        int min = 1000001;
        int dummy = -1;
        for(int i = start; i<=end; i++)
        {
            if(target < arr[i] && min > arr[i])
            {
                dummy = arr[i];
                min = arr[i];
            }
        }
        answer.push_back(dummy);
    }
    return answer;
}
```
