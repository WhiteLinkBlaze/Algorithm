# [두 수의 합](https://school.programmers.co.kr/learn/courses/30/lessons/181846)
## 풀이
+ 문자열의 형태로 연산을 진행
+ 연산의 편의를 위해 a 와 b간의 자릿수 차이를 메꾸어준다.
+ 각 문자열의 끝 자리끼리 더하기를 진행하고 10을 넘었다면 나머지는 answer에 추가하고 넘은 만큼(carry)은 다음차례로 넘긴다. 
+ 위의 단계를 반복하고 마지막 차수의 넘기지 못한 값(carry)이 있다면 처리한다.
+ answer를 뒤집어 answer를 완성하고 반환
## 코드
```cpp
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

string solution(string a, string b) {
    string answer = "";
    int diff = a.length() - b.length();
    int num = 0;
    diff = abs(diff);
    string dummy = "";
    //연산 편의를 위해 앞에 0을 붙임
    while(diff--) dummy+="0";
    
    if(a.length() < b.length()) a = dummy+a;
    else b = dummy+b;
    //연산 편의 구성 끝
		
    for(int i = b.length()-1; i >= 0; i--)
    {
        num += (a[i] - '0') + (b[i] - '0');
        answer.push_back(num%10+'0');
        num /= 10;
    }
    if(num > 0) answer.push_back(num%10+'0');
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
```