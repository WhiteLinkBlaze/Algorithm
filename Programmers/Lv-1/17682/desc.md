# [\[1차\] 다트 게임](https://school.programmers.co.kr/learn/courses/30/lessons/17682)
## 풀이
+ '점수''유형''option'의 형태를 가짐
+ 숫자를 기록하다가 유형을 만나면 일단 점수를 기록한다.
+ 옵션을 만나면 옵션을 적용한다.
	+ `*`는 해당 점수와 이전 점수에 반영된다.
	+ `#`은 해당 점수에만 반영된다.
+ 기록한 점수들을 총합하여 반환한다.
## 코드
```cpp
#include <string>
#include <cmath>
using namespace std;

int scoreFunc(int num, char SDT)
{
    int result = num;
    switch(SDT)
    {
        case 'S':
            break;
        case 'D':
            result = pow(num, 2);
            break;
        case 'T':
            result = pow(num, 3);
            break;
    }
    return result;
}
int solution(string dartResult) {
    int answer = 0;
    int score[3] = {0,};
    int cnt = 0;
    int num = 0;
    for(int i=0; i<dartResult.length();i++)
    {
        if('0' <= dartResult[i] && dartResult[i] <= '9')
        {
            //score
            num = num*10 + dartResult[i]-'0';
        }
        else if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T')
        {
            //single, double, triple
            score[cnt] = scoreFunc(num, dartResult[i]);
            num = 0;
            cnt++;
        }
        else
        {
            //option
            if(dartResult[i] == '*')
            {
                score[cnt-1] *= 2;
                if(cnt-2 >= 0)score[cnt-2] *=2;
            }
            else
            {
                score[cnt-1] *=(-1);
            }
        }
    }
    answer = score[2] + score[1] + score[0];
    return answer;
}
```