# [행렬의 덧셈](https://school.programmers.co.kr/learn/courses/30/lessons/12950)
## 풀이
+ 같은 행끼리 더하기를 수행하는 것
+ 주어진 2차원 배열에서 행을 뽑아내 다른 행렬의 행과 더하기 연산을 진행
+ `vector`를 매번 생성하는 것보다. `clear()`를 사용하면 조금은 시간 단축이 된다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> sum;
    for(int i = 0; i < arr1.size(); i++)
    {
        for(int j = 0; j < arr1[i].size(); j++)
        {
            sum.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(sum);
        sum.clear();
    }
    return answer;
}
```