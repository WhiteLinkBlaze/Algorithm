# [체육복](https://school.programmers.co.kr/learn/courses/30/lessons/42862)
##### 제한사항

- 전체 학생의 수는 2명 이상 30명 이하입니다.
- 체육복을 도난당한 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다.
- 여벌의 체육복을 가져온 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다.
- 여벌 체육복이 있는 학생만 다른 학생에게 체육복을 빌려줄 수 있습니다.
- 여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.
## 풀이
+ 정렬되어서 주어진다는 조건이 없어서 모두 정렬
+ 잃어버린 사람이 여벌의 체육복을 가지고 있던 사람이면 여벌을 가진 목록에서 제외한다.
	+ 그리고 잃어버린 사람 목록에서도 제외한다.

이제 여벌의 체육복을 가진 사람만이 없는 사람에게 빌려줄 수 있으므로
+ 여벌의 체육복을 가진 사람들의 목록을 확인한다.
+ 해당 사람의 앞 번호와 뒷 번호 사람이 잃어버린 사람인지 확인합니다. 
	+ 잃어버린 사람에 둘 중 한 명이 포함된다면 해당 사람을 목록에서 제외한다.

마지막으로 잃어버린 사람 목록 길이를 총 학생 수에서 빼어 결과를 구한다.
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    int idx = 0;
    while(idx < lost.size())
    {
        int ls = lost[idx];
        auto it = find(reserve.begin(), reserve.end(), ls);
        if(it != reserve.end())
        {
            auto lost_it = find(lost.begin(), lost.end(), ls);
            lost.erase(lost_it);
            reserve.erase(it);
            idx--;
        }
        idx++;
    }
    
    for(int res: reserve)
    {
        auto before_it = find(lost.begin(), lost.end(), res-1);
        auto after_it = find(lost.begin(), lost.end(), res+1);
        if(before_it != lost.end())
        {
            lost.erase(before_it);
        }
        else if(after_it != lost.end())
        {
            lost.erase(after_it);
        }
    }
    
    answer = n - lost.size();
    return answer;
}
```
```cpp title=''
#include <string>
#include <vector>

using namespace std;
int student[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i : reserve) student[i] += 1;
    for(int i : lost) student[i] += -1;
    for(int i = 1; i <= n; i++) {
        if(student[i] == -1) {
            if(student[i-1] == 1) 
                student[i-1] = student[i] = 0;
            else if(student[i+1] == 1) 
                student[i] = student[i+1] = 0;
        }
    }
    for(int i  = 1; i <=n; i++)
        if(student[i] != -1) answer++;

    return answer;
}


```