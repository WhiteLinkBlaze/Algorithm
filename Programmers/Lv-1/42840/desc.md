# [모의고사](https://school.programmers.co.kr/learn/courses/30/lessons/42840)
## 풀이
+ 각각의 수포자의 찍는 패턴을 미리 배열로 설정해둔다.
+ 수포자의 찍는 패턴과 해당 문제의 답안과 일치하면 각각의 정답 수에 1씩 추가한다.
+ 정답 수에서 최댓값을 추출한다.
+ 정답 수에서 최댓값을 가진 index를 구분하여 가장 많이 맞힌 수포자들을 결과에 포함시킨다.
## 코드
```cpp
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int sone[5] = {1,2,3,4,5};
    int stwo[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int sthree[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int cnt[3] = {0,0,0};
    
    for(int i=0; i<answers.size(); i++)
    {
        if(sone[i%5] == answers[i])
            cnt[0]++;
        if(stwo[i%8] == answers[i])
            cnt[1]++;
        if(sthree[i%10] == answers[i])
            cnt[2]++;
    }
    int max_cnt = max(cnt[0],max(cnt[1],cnt[2]));
    for(int i=0; i<3; i++)
    {
        if(max_cnt == cnt[i])
            answer.push_back(i+1);
    }
    return answer;
}
```