# [겹치는 선분의 길이](https://school.programmers.co.kr/learn/courses/30/lessons/120876)
## 풀이
### 1번
+ 3개의 선분을 하나의 지표면으로 적는 형태로 표현해, 겹치는 부분에 횟수를 적도록 한다.
+ `init`에서 하나의 배열에 선분이 가지는 영역마다 1씩 증가시켜 선분이 자리함을 표현한다.
+ `overlapping line`에서 겹친 선분 영역(배열에 2 이상으로 표현된 영역)을 구분하여 answer에 추가한다.
### 2번
+ 정렬에 대한 설명이 없어서 start 값 기준으로 내림차순 정렬을 먼저 해야한다.
+ 다음 선분이 왔을 때, 
	+ 이전 선분의 시작점(`prev_start`)과 현재 선분의 시작점(`cur_start`) 중에 가장 큰 값을 `cur_start`에 저장한다.
	+ 이전 선분의 끝점(`prev_end`)과 현재 선분의 끝점(`cur_end`) 중에 가장 작은 값을 `cur_end`에 저장한다.
	+ 이렇게 하면 이전 선분과 현재 선분의 교차하는 부분을 알 수 있다. 
		+ 교차하는 경우 `cur_start < cur_end` 
			+ (0,5),(1,9)
		+ 교차하지 않는 경우
			+ (0,5),(5,9)
	+ 교차하면 `prev_start=cur_end;`와 `prev_end = max(이전 선분의 끝점, 현재 선분의 끝점);`으로 새로운 선분을 구성해야한다.
		+ (0,5),(1,9) 라면 (5,9)가 구성되는데, 이렇게 하면 5 이전의 길이는 무시하고 다음 선분과의 겹치는 길이만을 고려할 수 있다. (정렬했기 때문에 무시 가능)
	+ 교차하지 않는 선분이라면, 현재의 선분으로 수정한다.
## 코드
```cpp title='1번'
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    int array[201] = {0,};
    int min_start = 300;
    int max_end = -300;
    //init
    for(int i = 0; i < 3; i++)
    {
        int start = lines[i][0] + 100;
        int end = lines[i][1] + 100;
        
        if(min_start > start) min_start = start;
        if(max_end < end) max_end = end;
        
        while(start < end)
        {
            array[start]++;
            start++;
        }
    }
    
    //overlapping line
    while(min_start < max_end)
    {
        if(array[min_start] >= 2)
        {
            for(int i = min_start; array[min_start] == array[i]; i++)
            {
                answer++;
                min_start = i;
            }
        }
        min_start++;
    }
    
    return answer;
}
```
```cpp title='2번'
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
bool comparison(vector<int> a, vector<int> b)
{
    if( a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> lines) {
    int answer = 0;
    sort(lines.begin(),lines.end());
    int prev_start = lines[0][0];
    int prev_end = lines[0][1];
    for(int i = 1; i < lines.size(); i++)
    {
        int cur_start = max(prev_start, lines[i][0]);
        int cur_end = min(prev_end, lines[i][1]);
        
        if(cur_start < cur_end)
        {
            answer+=cur_end-cur_start;
            prev_start = cur_end;
            prev_end = max(prev_end, lines[i][1]);
        }
        else
        {
            prev_start = lines[i][0];
            prev_end = lines[i][1];
        }
    }
    return answer;
}
```