# [성격 유형 검사하기](https://school.programmers.co.kr/learn/courses/30/lessons/118666)
## 풀이
구현 문제임
+ 성격 유형의 테이블`{"RT","CF","JM","AN"}` 성격 유형이 완성되면 순서는 RFMN 같은 식이된다.
+ survey에 담긴 원소는 어떤 두 가지 유형에 대한 조사를 담고 있음
+ choices는 해당 조사에 대한 선택 번호 (1~7)


+ map을 사용해서 어떤 성격 유형에 점수가 총 몇점인지를 기록
+ 한 조사에서 얻은 점수와 middle_score와의 차이가 음수면 왼쪽, 양수면 오른쪽 같으면 없는 점수임 (점수는 양수이어야 하므로 abs를 사용해 절댓값 적용)
+ 그렇게 구성한 map을 미리 만든 성격 유형의 테이블(`personality`)를 사용해서 순서대로 검색하여 집계하고 반환한다.
## 코드
```cpp
#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int middle_score = 4;
    vector<string> personality = {"RT","CF","JM","AN"};
    map<char,int> m;
    for(int i=0; i < survey.size(); i++)
    {
        int score = choices[i] - middle_score;
        if(score<0)//left
        {
            m[survey[i][0]] += abs(score);
        }
        else if(score>0)//right
        {
            m[survey[i][1]] += abs(score);
        }
    }
    for(string p : personality)
    {
        if(m[p[0]] < m[p[1]])answer += p[1];
        else answer += p[0];
    }
    return answer;
}
```
