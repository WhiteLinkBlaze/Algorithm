# [그림 확대](https://school.programmers.co.kr/learn/courses/30/lessons/181836)
## 풀이
주어진 그림 파일을 나타낸 문자열 배열의 내용을 k배 늘린 그림을 만들어야 한다. 그림은 2차원이므로 그림의 하나의 원소(pixel)을 k배 늘려야한다.
+ 매번 string 을 조작하기에는 시간이 우려되므로 미리 빈 배열을 만들어서 사용한다.
+ 원본 문자열 한 줄을 꺼내 원소마다 k배 늘린다.(좌우의 크기를 k배)
+ 이를 k회 반복한다(상하의 크기를 k배)

## 코드
```cpp
#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    for(string str : picture)
    {   
        char temp[201] = {0,};
        //k번 반복
        for(int loop_k = 0; loop_k < k; loop_k++)
        {
            //원본 문자열 탐색
            for(int i = 0; i < str.length(); i++)
            {
                //복사
                for(int j = i*k; j < (i+1)*k; j++)
                {
                    temp[j] = str[i];
                }
            }
            answer.push_back(string(temp));
        }
    }
    return answer;
}
```