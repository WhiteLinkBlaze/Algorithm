# [달리기 경주](https://school.programmers.co.kr/learn/courses/30/lessons/178871)
## 풀이
달리기 선수들이 있고, 이름이 불리면 해당 선수는 등수가 한 단계 올라간 것이 된다.

+ 선수들의 등수를 기록할 map을 하나 만든다.
+ 이름이 불려진 선수는 바로 앞 사람과 위치를 교환(swap)하고, 그 사람과의 등수를 수정한다.
## 코드
```cpp
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    map<string,int> m;
    for(int i=0;i<players.size();i++)
    {
        m[players[i]] = i;
    }
    for(string called : callings)
    {
        int start = m[called];
        int end = start-1;
        swap(answer[start],answer[end]);
        m[answer[start]] = start;
        m[answer[end]] = end;
    }
    return answer;
}
```
