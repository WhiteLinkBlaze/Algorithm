# [카드 뭉치](https://school.programmers.co.kr/learn/courses/30/lessons/159994)
## 풀이
+ 주어진 두 개의 카드 뭉치 위에서 한 장씩 뽑는다. 
	+ 두 가지 중 하나라도 이번 차례에 채워야할 단어와 같다면 해당 덱의 사용한 카드 수를 늘려 다음 카드를 가리키도록 한다.
	+ 사용한 카드 수의 합이 이전과 같다면 모두 만들 수 없는 문장이므로 반복을 그만한다.
+ 사용한 카드의 수와 사용해야할 카드의 수가 같다면 Yes를 반환
+ 아니라면 No를 반환한다.

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int used_card1 = 0;
    int used_card2 = 0;
    int check = 0;
    for(string str: goal)
    {
        if(used_card1 < cards1.size() && cards1[used_card1].compare(str) == 0) used_card1++;
        if(used_card2 < cards2.size() && cards2[used_card2].compare(str) == 0) used_card2++;
        
        if(check == used_card1 + used_card2)break;
        check = used_card1 + used_card2;
    }
    if(check == goal.size()) answer = "Yes";
    else answer = "No";
    return answer;
}
```
