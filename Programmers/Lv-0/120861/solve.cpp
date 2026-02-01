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