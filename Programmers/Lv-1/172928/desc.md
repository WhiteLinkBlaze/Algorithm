# [공원 산책](https://school.programmers.co.kr/learn/courses/30/lessons/172928)
## 풀이
+ 미리 이동 방향으로 이동 했을 때의 연산을 좌표로 기록한다.
+ 중간에 장애물이 있는 경우를 구분하기 위해 한 칸씩 이동하면서 확인해야한다.
	+ 중간에 벽을 만나면 그 이동은 무효
	+ 중간에 공원의 범위를 넘어가면 그 이동은 무효
+ 이동에 무효가 없었다면 이동한 위치로 현재 위치를 갱신함

## 코드
```cpp
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer = vector<int>(2,0);
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    map<char,int> dir_mapping  = {{'S',0},{'N',1},{'E',2},{'W',3}};
    //init
    int W = park[0].size(), H = park.size();
    int next_x, next_y;
    for(int i = 0; i < park.size(); i++)
    {
        if(park[i].find("S") != string::npos)
        {
            answer[0] = i;
            answer[1] = park[i].find("S");
            break;
        }
    }
    //process
    for(auto& route : routes)
    {
        stringstream in(route);
        char dir; 
        int move;
        in >> dir;
        in >> move;
        int cx = answer[1];
        int cy = answer[0];
        while(move--)
        {
            cx += dx[dir_mapping[dir]];
            cy += dy[dir_mapping[dir]];
            if(!((cx >= 0 && cx < W) && (cy >= 0 && cy < H)))break;
            if(park[cy][cx] == 'X')break;
        }
        if(move < 0)
        {
            answer[0] = cy;
            answer[1] = cx;
        }
    }
    return answer;
}
```
