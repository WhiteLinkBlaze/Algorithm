# [평행](https://school.programmers.co.kr/learn/courses/30/lessons/120875)
## 풀이
> [!note] 기울기 공식  = (y의 증가량)/(x의 증가량)

네 개의 좌표를 두 개씩 짝지어 만든 선분들끼리 기울기를 비교하도록 한다. 이때 나올 수 있는 선분의 개수는 6개이다.
+ 01 23 : (0번 좌표, 1번 좌표) (2번 좌표, 3번 좌표)
+ 02 13 : (0번 좌표, 2번 좌표) (1번 좌표, 3번 좌표)
+ 03 12 : (0번 좌표, 3번 좌표) (1번 좌표, 2번 좌표)
0번으로 만들 수 있는 선분을 모두 만들고 나머지 선분과 역순으로 비교한다.
### 기울기 공식을 사용할 경우
+ 나눗셈을 사용하기 때문에 정수로 계산하면 소수점이 사라져 버리기 때문에 실수형 자료형(double)로 계산해야한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
double slope(const int x1,const int y1,const int x2,const int y2)
{
    if(x1 > x2)
        return (double)(y1 - y2) / (x1 - x2);
    else
        return (double)(y2 - y1) / (x2 - x1);
}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    vector<double> slopList = vector<double>();
    double tempSlope = 0;
    for(int j = 1; j < dots.size();j++)
    {
        tempSlope = slope(dots[0][0],dots[0][1],dots[j][0],dots[j][1]);
        slopList.push_back(tempSlope);
    }
    for(int j = 1; j < dots.size()-1; j++)
    {
        for(int i = j+1; i < dots.size(); i++)
        {
            tempSlope = slope(dots[j][0],dots[j][1],dots[i][0],dots[i][1]);
            if(slopList.back() == tempSlope) return 1;
            slopList.pop_back();
        }
    }
    return answer;
}
```