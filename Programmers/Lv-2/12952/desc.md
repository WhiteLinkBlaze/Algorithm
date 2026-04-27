# [N-Queen](https://school.programmers.co.kr/learn/courses/30/lessons/12952)
## 풀이 - 백트래킹
추상적인 범위보다는 접근해야할 범위만 접근하는 것이 풀이가 용이하다.
+ 행을 1씩 늘려가면서 퀸의 위치를 설정한다. -> 벡터에 넣는다.
+ 현재 행에서 놓을 수 있는 위치를 고른다. -> 벡터에 존재하는 좌표 값들과 비교한다.
+ 놓을 수 있다면 현재 좌표를 값에 넣고 다음 행으로, 놓을 수 없다면 넘어간다.
+ 다 놓고 돌아왔을 때는 마지막 것을 뺀다. -> 넣었던 것을 빼게 된다.

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
int nQueen(vector<vector<int>>& pos, int row, int end)
{
    int answer =0;
    if(end == row)return 1;
    bool check;
    for(int col = 0; col < end; col++)
    {
        check = true;
        for(int j=0; j<row; j++)
        {
            //row
            if(pos[j][0] == col)check = false;
            //x+y
            else if(pos[j][0] + pos[j][1] == col + row)check = false;
            //x-y
            else if(pos[j][0] - pos[j][1] == col - row)check = false;
            if(!check)break;
        }
        if(check)
        {
            pos.push_back({col, row});
            answer += nQueen(pos, row+1,end);
            pos.pop_back();
        }
        
    }
    return answer;
}
int solution(int n) {
    int answer = 0;
    vector<vector<int>> map;
    answer = nQueen(map, 0, n);
    return answer;
}
```
