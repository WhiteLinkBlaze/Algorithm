# [등수 매기기](https://school.programmers.co.kr/learn/courses/30/lessons/120882)
## 풀이

원본 배열의 순서에 맞게 등수를 매겨서 반환해야 하는 문제다.

따라서 정렬 기능을 사용하는데 정렬에 사용될 elements는 과목 점수합, 원본의 index 이렇게 구성한다.

+ elements 기반으로 내림차순으로 정렬한다.
+ 이전 학생의 index를 기록해두고 이전 등수의 학생과 점수 합을 비교하여 같으면 이전 등수의 등수를 현재 학생에게 부여한다.
+ 다르면 다음 등수를 부여 받는다.

## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comparison(pair<int,int> a, pair<int,int> b)
{
    return a.first > b.first;
}
vector<int> solution(vector<vector<int>> score) {
    vector<int> answer = vector<int>(score.size(),1);
    vector<pair<int,int>> averageScore = vector<pair<int,int>>();
    
    for(int i = 0; i < score.size(); i++)
    {
        int eng = score[i][0];
        int math = score[i][1];
        int sum = eng+math;
        averageScore.push_back(make_pair(sum,i));
    }
    sort(averageScore.begin(), averageScore.end(), comparison);
    
    int beforeStudent = averageScore[0].second;
    for(int i = 1; i < averageScore.size(); i++)
    {
        int rank = i+1;
        int curStudent = averageScore[i].second;
        if(score[beforeStudent][0] + score[beforeStudent][1] 
           == score[curStudent][0] + score[curStudent][1])
            rank = answer[beforeStudent];
        answer[curStudent] = rank;
        beforeStudent = curStudent;
    }
    return answer;
}
```
