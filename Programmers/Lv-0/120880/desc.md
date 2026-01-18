# [특이한 정렬](https://school.programmers.co.kr/learn/courses/30/lessons/120880)
## 풀이
+ 정렬에 조건을 붙이는 문제임
+ 거리를 포함하는 새로운 배열`numDistanceList`를 구성하고, 해당 원소는 `{거리, 값}`의 형태로 넣는다.
+ 해당 원소를 기반으로 정렬할 수 있도록 함수`comparison()`을 구성한다. 거리 비교 후 같으면 값 비교
+ `numDistanceList`를 정렬
+ 앞에서부터 탐색하여 값을 answer에 집어 넣고 반환한다.

## 코드
```cpp
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool comparison(pair<int,int> a, pair<int,int>b)
{
    if(a.first == b.first) return a.second > b.second;
    return a.first<b.first;
}
vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<pair<int,int>> numDistanceList;
    for(int i=0; i<numlist.size();i++)
    {
        numDistanceList.push_back(make_pair(abs(numlist[i]-n),numlist[i]));
    }
    sort(numDistanceList.begin(),numDistanceList.end(),comparison);
    for(int i=0; i<numlist.size();i++)
        answer.push_back(numDistanceList[i].second);
    return answer;
}
```