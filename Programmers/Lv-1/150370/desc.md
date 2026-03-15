# [개인정보 수집 유효기간](https://school.programmers.co.kr/learn/courses/30/lessons/150370)
## 풀이
+ 주어진 날짜를 일 단위로 변환하여 계산을 진행
+ 약관 종류에 따른 증가량을 일단위로 바꾸고 약관 종류에 맵핑함
+ 수집된 날짜와 약관 종류의 일수 합을 구하여 그것이 오늘날 보다 같거나 큰지를 확인
	+ 같거나 크다면 해당 정보는 파기해야할 개인정보임
	

## 첨언
+ stringstream을 남발하지 않는 것이 좋다고함
## 코드
```cpp
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
int calculateDays(const string& date)
{
    int y = stoi(date.substr(0,4));
    int m = stoi(date.substr(5,2));
    int d = stoi(date.substr(8,2));
    return (y*12*28) + (m*28) + d;
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    //모든 달은 28일까지 있다고 가정합니다.
    //init: today; 일 단위로 변환
    int todayTotalDays = calculateDays(today);
    
    //init: terms map; 유형에 따른 기간 정보를 맵핑
    map<string, int> termMap;
    for(string t : terms)
    {
        int spaceIdx = t.find(' ');
        string type = t.substr(0,spaceIdx);
        int duration = stoi(t.substr(spaceIdx+1));
        termMap[type] = duration * 28;
    }
    
    //process
    for(int i = 0; i < privacies.size(); i++)
    {
        string dateP = privacies[i].substr(0,10);
        string typeP = privacies[i].substr(11);
        
        int collectedDays = calculateDays(dateP);
        int expirationDays = termMap[typeP];
        
        //수집일 + 유효기간 <= 오늘
        if(collectedDays + expirationDays <= todayTotalDays)
        {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}
```
