# [신고 결과 받기](https://school.programmers.co.kr/learn/courses/30/lessons/92334)
## 풀이
+ `id_list_map`: 계정, index를 연결해줄 맵
+ `reported_id_map`: 해당 계정이 신고를 받은 횟수를 기록할 맵
	+ unoredered_map을 사용해서 순서를 유지함
+ `reported`: `reported[0][1]` 0번 인덱스의 유저가 1번 인덱스의 유저를 신고했다. 라는 기록용 2차원 vertor
### init: id_list_map, reported
+ 기본적인 초기화 과정

### process: report
report에서 값을 읽어들여 결과를 기록함
+ `reported_id_map`: 신고를 한 유저에게서 여러번 받을 수 있기 때문에 한 번씩만 받아 기록할 수 있도록 함
+ `reported`: 누가 누구를 신고했는지 기록함

### process: suspended id
정지된 계정을 추출함 -> `suspended_id`
+ `reported_id_map`에 있는 값을 받아 기준치(k)보다 같거나 높으면 정지된 계정에 포함시킴

### process: make answer
`reported`에서 원소를 한 번 추출하면 `vector<int>`의 값(`report_count`)이 나온다. 이는 해당 유저가 어느 유저를 신고 했는지 기록한 `vector`임
+ 신고당한 유저의 이름 `suspended_id`에서 추출해 `report_count`의 값에서 해당 유저를 신고했는지 확인한다.
	+ 누가 누구를 신고해서 정지되었을 때 해당 유저가 정지 되었다는 알림을 들어야 하는데 신고자들이 이러한 알림을 몇 번 들어야 하는지 반환해야하므로
	+ 신고했다면 `cnt++`
+ 추출된 cnt 값을 `answer`에 저장
## 다른 분의 깔끔한 방법을 보고
인상적인 부분을 기록
```cpp title='bits/stdc++.h ?'
#include <bits/stdc++.h>
```
```cpp title='stringstream'
stringstream in(s);
string a, b; in >> a >> b;
```
```cpp title='중복 제거'
vector<pair<int, int>> v;
sort(report.begin(), report.end());
report.erase(unique(report.begin(), report.end()), report.end());
```
```cpp title='map 원소 추출, 카운팅, 결과 구성'
vector<int> cnt(n), ret(n);
for (const auto& [a, b] : v) cnt[b]++;
for (const auto& [a, b] : v) if (cnt[b] >= k) ret[a]++;
```
## 코드
```cpp
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> id_list_map;
    unordered_map<string, int> reported_id_map;
    vector<vector<int>> reported;
    
    //init id_list_map, reported;
    for(int i = 0; i < id_list.size(); i++)
    {
        id_list_map[id_list[i]] = i;
        reported_id_map[id_list[i]]=0;
        reported.push_back(vector<int>(id_list.size(),0));
    }
    //process report
    for(string log : report)
    {
        string report_user = log.substr(0,log.find(' '));
        string reported_user = log.substr(log.find(' ')+1);
        if(reported[id_list_map[report_user]][id_list_map[reported_user]]==0)reported_id_map[reported_user]++;
        reported[id_list_map[report_user]][id_list_map[reported_user]] = 1;
    }
    
    //process suspended id
    vector<string> suspened_id;
    for(auto iter : reported_id_map)
    {
        if(iter.second >= k)suspened_id.push_back(iter.first);
    }
    
    //process make answer
    for(vector<int> report_count : reported)
    {
        int cnt = 0;
        for(string target : suspened_id)
        {
            if(report_count[id_list_map[target]])cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}
```

```cpp title='다른분의 깔끔한 방법'
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 1.
    const int n = id_list.size();
    map<string, int> Conv;
    for (int i = 0; i < n; i++) Conv[id_list[i]] = i;

    // 2.
    vector<pair<int, int>> v;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    for (const auto& s : report) {
        stringstream in(s);
        string a, b; in >> a >> b;
        v.push_back({ Conv[a], Conv[b] });
    }

    // 3.
    vector<int> cnt(n), ret(n);
    for (const auto& [a, b] : v) cnt[b]++;
    for (const auto& [a, b] : v) if (cnt[b] >= k) ret[a]++;
    return ret;
}
```