# [배열 만들기2](https://school.programmers.co.kr/learn/courses/30/lessons/181921)
## 풀이
+ bit의 구조가 생각나서 bit를 활용해서 답안을 구현해보기로 했다.
+ bitStart와 bitLimit는 찾을 숫자의 시작점과 사용할 bit의 개수를 구성한다.
	+ bitStart: 찾을 숫자의 시작점
		+ 10 -> 1 (50부터 찾기 시작함)
		+ 5 -> 0 (5부터 찾기 시작함)
		+ 555 -> 2 (500부터 찾기 시작함)
	+ bitLimit: 사용할 bit의 개수
		+ 555 -> 3개 (2진수 111 까지 구성)
		+ 10 -> 2개 (2진수 11까지 구성)
+ bit에 1씩 더해가며 해당 bit 구성에 true면 해당 차수의 5를 추가한다.
	+ `num += 5*pow(10,i);`
+ 숫자를 다 구성하고 bit수를 1 올린다.
+ 구성한 숫자가 조건에 맞는지 검사한다.
+ 비어있다면 -1 추가하고 answer 반환
### bit
+ 2진수의 형태로 1이 증가해서 2가 되면 바로 다음차수의 값이 1 증가한다.
	+ 1 + 1 -> 10 의 형태임
	+ 11 + 1 -> 100


## 코드
```cpp
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    bool bits[6] = {false,};
    int bitLimit = (int) log10((double)r)+1;
    int bitStart = (int) log10((double)l);
    bits[bitStart] = true;
    int limit = pow(2,bitLimit) - pow(2,bitStart);
    for(int k=0;k<limit;k++)
    {
				//숫자 구성
        int num = 0;
        for(int i=0; i<bitLimit; i++)
        {
            if(bits[i])
                num += 5*pow(10,i);
        }
				//bit 1 증가
        bool check = true;
        int index = 0;
        while(check)
        {
            bits[index] = !bits[index];
            if(!bits[index])
                index++;
            else
                check = !check;
            if(index == bitLimit) break;
        }
				//구성한 숫자가 조건에 맞는지 검사
        if(l <= num && num <=r)
            answer.push_back(num);
    }
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}
```