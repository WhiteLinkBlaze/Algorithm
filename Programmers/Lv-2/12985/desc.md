# [예상 대진표](https://school.programmers.co.kr/learn/courses/30/lessons/12985)
## 풀이
우승자를 왼쪽 칸으로 이동케 한다면 최악의 경우 0에서 만나게 될 것이다. 이 때까지의 answer를 기록한다.
## 내 케이스: 처음에 생각한 것 
- 하나의 그룹 블록을 생각한다.
- 그룹 블록은 승자와 패자가 존재하는 블록이고 이 블록은 처음 순회에서 2칸짜리이고 다음 순번에는 4칸, 8칸, 16칸 이런 식으로 증가한다.
- 각 블록의 승자는 맨 앞으로 이동한다.(1번부터 시작했다면 4칸짜리 블록의 승자는 1번 칸으로 이동한다.)
- 이렇게 그룹블록의 값을 비교하는데 p1, p2의 조합이 a, b를 만족한다면 -1을 반환하여 해당 라운드를 반환한다.
- logN 이지만 조건 연산이 많다.

## 개선안
- 1을 2로 나누면 0이다.
- 2를 2로 나누면 1이고, 1을 2로 나누면 0이다.
- 3을 2로 나누면 1이다. 1을 2로 나누면 0이다.
- 결국 2로 계속 나누면 같은 곳에서 만나게 된다.
- 그렇다면 a와 b를 2로 나누는 횟수를 카운트해서 반환하면 원하는 값(a와 b가 만나는 라운드)이 된다.

## 코드
```cpp
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer=0;a--;b--;
    while(a!=b){
        a=a/2;
        b=b/2;
        answer++;
    }
    return answer;
}
```

```cpp
#include <iostream>
#include <vector>

using namespace std;
int winner(const int& p1,const int& p2,const int& conA, const int& conB)
{
    if((p1 == conA && p2 == conB) || (p1 == conB && p2 == conA))return -1;
    else if(p1 == conA || p2 == conA) return conA;
    else if(p1 == conB || p2 == conB) return conB;
    return p1;
}
int solution(int n, int a, int b)
{
    int answer = 1;
    int offset = 1;
    int round = 1;
    vector<int> list(n+1,0);
    list[a] = a;
    list[b] = b;
    while(offset <= n)
    {
        for(int i = 1; i + offset <= n; i+= offset*2)
        {
            if(list[i] == 0 && list[i+offset] == 0)continue;
            list[i] = winner(list[i], list[i+offset], a, b);
            if(list[i] == -1) return round;
        }
        round++;
        offset*=2;
    }
    return answer;
}
```