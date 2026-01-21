# [전국 대회 선발고사](https://school.programmers.co.kr/learn/courses/30/lessons/181851)
## 풀이
+ 참석 가능 여부로  참석할 수 없는 학생들을 먼저 걸러낸다.
+ 참석할 수 있는 학생들은 sortedRank에 Rank, index를 기록한다.
+ Rank를 기준으로 오름차순 정렬한다.
+ 높은 등수의 3명이므로 0, 1, 2 위치의 학생들의 index 값을 통해 answer를 구성했다.
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comparison(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}
int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    vector<pair<int,int>> sortedRank;
    for(int i=0; i<rank.size();i++)
    {
        if(attendance[i])
            sortedRank.push_back(make_pair(rank[i],i));
    }
    sort(sortedRank.begin(), sortedRank.end(),comparison);
    answer = 10000*sortedRank[0].second + 100*sortedRank[1].second+sortedRank[2].second;
    return answer;
}
```