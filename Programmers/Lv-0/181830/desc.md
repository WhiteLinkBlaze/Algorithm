# [정사각형으로 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/181830)
## 풀이
+ 행 개수와 열 개수의 차이만큼 행 or 열을 늘려야한다.
## 코드
```cpp
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    int col = arr[0].size();
    int row = arr.size();
    while(row > col)
    {
        for(int i=0;i<row; i++)
        {
            arr[i].push_back(0);
        }
        col = arr[0].size();
    }
    while( col > row)
    {
        arr.push_back(vector<int>(col,0));
        row = arr.size();
    }
    answer = arr;
    return answer;
}
```