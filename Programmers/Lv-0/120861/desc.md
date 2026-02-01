# [캐릭터의 좌표](https://school.programmers.co.kr/learn/courses/30/lessons/120861)
## 풀이
이전에 풀었던 문제이다. 설명은 따로 적지 않았었기에 지금 적는다.

Point 구조체를 만들어서 구현해 보았다. 중요한 것은 board 판의 끝에 도달하게 되면 움직이는 것을 무시하는 것이므로, move함수에 board에 대한 정보를  전달한다. (maxX, maxY)

보드판은 음수에서 양수까지 존재하기 때문에 maxX, maxY 각각 절반만큼을 더해서 양수의 형태로 만들었다.

모든 움직임 처리를 하고 나서 maxX의 절반, maxY의 절반을 빼서 보드의 내용을 원래대로의 범위로 반영하고 반환한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
typedef struct Point{
    int x;
    int y;
    void move(const int moveX, const int moveY, const int maxX, const int maxY)
    {
        x = x+moveX < 0 ? 0:x+moveX;
        x = x > maxX ? maxX : x;
        y = y+moveY < 0 ? 0:y+moveY;
        y = y > maxY ? maxY : y;
    }
}Point;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    int maxX = (board[0]-1), maxY = (board[1]-1);
    Point dummyAnswer = {maxX/2,maxY/2};
    for(string key: keyinput)
    {
        switch(key[0])
        {
            case 'l':
                dummyAnswer.move(-1,0,maxX,maxY);
                break;
            case 'r':
                dummyAnswer.move(1,0,maxX,maxY);
                break;
            case 'u':
                dummyAnswer.move(0,1,maxX,maxY);
                break;
            case 'd':
                dummyAnswer.move(0,-1,maxX,maxY);
                break;
        }
    }
    answer.push_back(dummyAnswer.x-maxX/2);
    answer.push_back(dummyAnswer.y-maxY/2);
    return answer;
}
```
