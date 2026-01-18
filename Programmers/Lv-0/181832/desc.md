# [정수를 나선형으로 배치하기](https://school.programmers.co.kr/learn/courses/30/lessons/181832)
## 풀이
나선형으로 배열을 참조하게 되면 x 증가 -> y 증가 -> x 감소 -> y 감소 의 형태를 반복하게 된다. 연산 방법에 따라 index위치가 어긋날 수 있으니 조절할 것
## 코드
```cpp
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer = vector<vector<int>>(n , vector<int>(n,0));
    int num = 1;
    int count = 0;
    int x = 0, y = 0;
    while(num <= n*n)
    {
        //x증가
        while(x < n - count)
        {
            answer[y][x++] = num++;
        }
        x--;
        y++;
        //y증가
        while(y < n - count)
        {
            answer[y++][x] = num++;
        }
        y--;
        x--;
        //x감소
        while(x >= count)
        {
            answer[y][x--] = num++;
        }
        x++;
        y--;
        //y감소
        while(y > count)
        {
            answer[y--][x] = num++;
        }
        x++;
        y++;
        count++;
    }
    return answer;
}
```