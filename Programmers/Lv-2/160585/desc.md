# [혼자서 하는 틱택토](https://school.programmers.co.kr/learn/courses/30/lessons/160585)
## 풀이
```text
OXO  
XOX  
OXO
```
+ 보드 전체를 대상으로 win check하는 게 맞다. - 착수 순서를 모르기 때문에 위의 경우를 걸러낼 수 없다.
+ 그리고 O의 개수와 X의 개수를 따로 뽑는다.
+ 위 두 가지를 기반으로 올바른 진행이 아닌지를 걸러내어 결과를 반환하도록 한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
bool win_check(vector<string> & board, char player)
{
    
    for(int i=0; i<3; i++)
    {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)return true;
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)return true;
    }
        
    
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)return true;
    if(board[2][0] == player && board[1][1] == player && board[0][2] == player)return true;
    return false;
}
int solution(vector<string> board) {
    int answer = 1;
    int cnt_o = 0;
    int cnt_x = 0;
    bool win_o = win_check(board, 'O');
    bool win_x = win_check(board, 'X');
    
    for(string str : board)
    {
        for(char ch : str)
        {
            if(ch == 'O')cnt_o++;
            else if(ch == 'X')cnt_x++;
        }
    }
    
    //잘못될 조건이란 무엇인가?
    if(!(0 <= cnt_o - cnt_x && cnt_o - cnt_x <=1))return 0;
    if(win_o && cnt_o - cnt_x == 0)return 0;
    if(win_x && cnt_x < cnt_o) return 0;
    return answer;
}
```