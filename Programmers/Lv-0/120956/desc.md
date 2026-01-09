# 옹알이 (1)
## 풀이
문자열을 생성하고 그대로 대입하는 걸 반복하면 메모리 할당하는 시간 때문에 시간초과가 날 수 있다. 포인터를 쓰거나, 미리 구성해두고 index로 참조하거나 하는 식으로 이 시간을 아낄 수 있다.
1. 주어진 문자열의 앞글자를 구분한다.
	+ 아이가 발음 할 수 있는 문장은 4가지이고, 각각 앞글자가 다르다.
	+ 앞글자를 통해 발음할 수 있는 내용인지 구분한다.
2. 구분한 문자열로 어떤 말을 하려는지 확인할 targetString을 구성한다.
3. targetString의 길이보다 babbling\[i]의 남은 길이가 짧다면 발음할 수 없는 문자열이므로 넘어간다.
4. targetString의 길이보다 babbling\[i]의 길이가 충분하다면 targetString과 babbling\[i]에서 targetString의 길이 만큼 부분 문자열을 추출하여 비교한다.
	+ 비교해서 같다면 아직까진 발음 가능
		+ 이후 인덱스를 targetLength-1만큼 증가시키고 다음으로 넘어간다.
	+ 다르다면 발음 할 수 없으므로 다음으로 넘어간다. j = babbling\[i].length();
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string targetString[] = {"aya", "ye","woo", "ma"};
    int targetIndex = 0;
    int targetLength = 0;
    bool check = true;
    for(int i = 0; i < babbling.size(); i++)
    {
        check = true;
        for(int j = 0; j < babbling[i].length(); j++)
        {
            switch(babbling[i][j])// 앞글자 구분
            {
                case 'a':
                    targetIndex = 0;
                    break;
                case 'y':
                    targetIndex = 1;
                    break;
                case 'w':
                    targetIndex = 2;
                    break;
                case 'm':
                    targetIndex = 3;
                    break;
                    
            }
            
            targetLength = targetString[targetIndex].length();
            
            if(babbling[i].length() - j >= targetLength && 
                targetString[targetIndex].compare(babbling[i].substr(j,targetLength))==0)
                j+=targetLength-1;
            else
            {
                j = babbling[i].length();
                check = false;
            }
        }
        if (check) answer++;
    }
    return answer;
}
```


## 참고 자료
---
+ [프로그래머스](https://school.programmers.co.kr/learn/courses/30/lessons/120956)
