# [직사각형 넓이 구하기](https://school.programmers.co.kr/learn/courses/30/lessons/120860)
## 풀이
한 점을 정하고 다른 점들과 비교한다. 조건 중에 2차원 좌표 평면에 변이 축과 평행한 직사각형이기 때문에 찾기 쉽다.
+ x 를 비교했는데 같다. -> y좌표를 통해 길이를 구한다.
+ y 를 비교했는데 같다. -> x좌표를 통해 길이를 구한다.
+ 구한 길이들을 통해 직사각형의 넓이는 구한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    int x = dots[0][0];
    int y = dots[0][1];
    int x_lineLength = 0;
    int y_lineLength = 0;
    for(int i = 1; i < dots.size(); i++)
    {
        if(x == dots[i][0])
        {
            y_lineLength = y - dots[i][1];
        }
        if(y == dots[i][1])
        {
            x_lineLength = x - dots[i][0];
        }
    }
    x_lineLength *= x_lineLength < 0 ? -1 : 1;
    y_lineLength *= y_lineLength < 0 ? -1 : 1;
    answer = x_lineLength * y_lineLength;
    return answer;
}
```