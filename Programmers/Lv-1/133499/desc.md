# [옹알이 (2)](https://school.programmers.co.kr/learn/courses/30/lessons/133499)
## 풀이
[옹알이](https://school.programmers.co.kr/learn/courses/30/lessons/120956)에서 풀었던 것과 비슷한데, 연속해서 같은 발음을 하는 것을 어려워 한다는 조건이 새로 생겼다.
+ 이전에 발음했던 것과 같은 지 비교해야한다. 
+ `before_idx == idx`를 통해 이전에 발음 했던 것과 이번에 발음할 것이 같은지 비교한다.
## 코드
```cpp
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string list[4] = {"aya", "ye", "woo", "ma"};
    bool check;
    int idx = 0;
    int before_idx;
    for(string& babb: babbling)
    {
        check = true;
        before_idx = -1;
        for(int i = 0;check && i < babb.length(); i++)
        {
            switch(babb[i])
            {
                case 'a':
                    idx = 0;
                    break;
                case 'y':
                    idx = 1;
                    break;
                case 'w':
                    idx = 2;
                    break;
                case 'm':
                    idx = 3;
                    break;
                default:
                    check = false;
            }
            if(before_idx == idx
                || i + list[idx].length() > babb.length()
                || list[idx].compare(0,list[idx].length(), babb, i,list[idx].length())!=0)
            {
                check = false;
            }
            else 
            {
                i+= (list[idx].length()-1);
                before_idx = idx;
            }
        }
        if(check)
        {
            answer++;
        }
    }
    return answer;
}
```
