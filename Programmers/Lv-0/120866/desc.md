# [안전지대](https://school.programmers.co.kr/learn/courses/30/lessons/120866)
## 풀이
+ 위험한 위치를 기록하는 배열을 하나 만든다.(`dangerBoard`)
+ 원본 Board를 탐색하여 폭탄을 발견하면 dangerBoard에 상하좌우 대각선과 해당 위치 총 9가지를 기록하고 이미 기록된 위치는 무시한다. 그리고 기록한 횟수만큼을 반환한다.`signDangerBoard`
+ 기록한 횟수를 받으면 안전한 위치 개수를 적은 값에서 뺀다. `safeBoardNum-=signDangerBoard(...);`
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
bool checkBoundary(const int size, const int xpos, const int ypos)
{
    if(xpos < 0 || ypos < 0 || xpos >= size || ypos >= size) 
        return false;
    return true;
}
int signDangerBoard(vector<vector<int>>& board, const int xpos, const int ypos)
{
    int answer = 0;
    int list[9][2]=
    {
        {-1,1},{0,1},{1,1},
        {-1,0},{0,0},{1,0},
        {-1,-1},{0,-1},{1,-1}
    };
    
    for(int i=0; i<9; i++)
    {
        if(checkBoundary(board.size(),xpos + list[i][0], ypos + list[i][1]))
        {
            if(board[ypos+list[i][1]][xpos+list[i][0]] == 1)
                continue;
            else
                board[ypos+list[i][1]][xpos+list[i][0]]=1;
            answer++;
        }
    }
    return answer;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    int size = board.size();
    int safeBoardNum = size*size;
    vector<vector<int>> dangerBoard(size,vector<int>(size,0));
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(board[i][j] == 1)
            {
                safeBoardNum = safeBoardNum - signDangerBoard(dangerBoard,i,j);
            }
        }
    }
    answer = safeBoardNum;
    return answer;
}
```
