# [주사위 게임 3](https://school.programmers.co.kr/learn/courses/30/lessons/181916)
## 풀이
+ 6면체 주사위 네 개를 사용하여 나온 숫자에 따라 점수를 계산하는 게임이다.
+ 주사위의 면은 6면이므로 6가지를 표현할 수 있는 배열을 사용(`int arr[7]`);
+ 주사위를 굴려서 나온 칸에 나온 개수를 표시한다. 
	+ (1,2,3,4 이면 `arr[1]++;,arr[2]++;,arr[3]++;,arr[4]++;`)이런식

점수 조건
1. 네 개가 같은 숫자 p면 `1111*p`;
2. 세 개가 같은 숫자 p, 다른 하나의 숫자 q 이면, `(10*p+q)^2`
3. 두 개씩 같은 숫자인 주사위 두 가지를 각각 p, q라고 하면,  `(p+q)*|p-q|`
4. 어느 두 주사위에서 나온 숫자가 p로 같고 나머지 두 주사위에서 나온 숫자가 각각 p와 다른 q, r이라면 `q*r`
5. 네 주사위 모두 다른 숫자라면 나온 숫자중 가장 작은 숫자

+ p에는 가장 처음 한 번 그리고 개수가 많은 숫자만 들어간다.(4,3,2)
+ q에는 p가 들어가고 나서 (2,1)
+ r에는 p, q 이후의 나머지 (1)
이렇게 들어갈 수 있도록 switch문을 구성하고, 반복은 6에서부터 1까지 갈 수 있도록 하면 r에는 자연스럽게 가장 작은 숫자가 들어간다.

이후에는 구성한 p, q, r과 주사위 나온 조합
+ case: 4
	+ 던지는 주사위가 총 4개이므로, 네 개가 같은 숫자는 하나만 나올 수 있음
+ case: 3 1
	+ 던지는 주사위가 총 4개이므로, 세 개가 같은 숫자는 하나만 나올 수 있음 남은 하나도 다섯 가지 중 하나임
+ case: 2 2
	+ case: 2 1 1 과 겹칠 수 있음
	+ `arr[p] == arr[q]`로 검사하면 case: 1 1 1 1 과 겹침
+ case: 2 1 1
	+ `arr[q] == arr[r]`로 검사하면 case: 1 1 1 1과 겹침
+ case: 1 1 1 1
	+ 위의 검사하고 전부 아니었다면 이것밖에 없다.
## 코드
```cpp
#include <string>
#include <vector>
#include <cmath>

using namespace std;
int square(int a)
{
    return a*a;
}
int solution(int a, int b, int c, int d) {
    int answer = 0;
    int arr[7] = {0,};
    arr[a]++;arr[b]++;arr[c]++;arr[d]++;
    int p = 0, q = 0, r = 0;
    for(int i=6;i>0;i--)
    {
        switch(arr[i])
        {
            case 4:
            case 3:
                p = i;
                break;
            case 2:
                if(p == 0) 
                    p = i;
                else if(q == 0) 
                    q = i;
                break;
            case 1:
                if(q == 0)
                    q = i;
                else
                    r = i;
        }
    }
    if(arr[p] == 4)                     // case 4
        answer = 1111*p;
    else if(arr[p] == 3)                // case 3 1
        answer = square(10*p+q);
    else if(arr[p] == 2 && arr[q] == 2) // case 2 2
        answer = (p+q) * abs(p-q);
    else if(arr[p] == 2 && arr[r] == 1) // case 2 1 1
        answer = q*r;
    else                                // case 1 1 1 1
        answer = r;
    return answer;                          
}
```