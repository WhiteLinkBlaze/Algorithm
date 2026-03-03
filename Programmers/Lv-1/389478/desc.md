# [택배 상자 꺼내기](https://school.programmers.co.kr/learn/courses/30/lessons/389478)
## 풀이
상자를 `vector`에 쌓았다.
+ 범위가 0 ~ w-1 임
+ 방향은 0에서 커지다 w-1에서 멈추고 w-1에서 다시 0으로 이동하는 것을 반복
+ 이동을 하면서 번호를 메긴 상자들을 `vector`에 집어넣고 집어넣는 와중에 나중에 찾을 상자라면 위치를 기록한다.(idx, idy)
+ 기록한 위치를 기반으로 answer를 구성
	+ 내가 원하는 상자 라인에는 몇 개의 상자가 쌓였는가 `boxes[idx].size()`
	+ 내가 원하는 상자를 빼려면 `총 상자 개수 - 내 상자 위치`만큼 빼야한다.
### 다른 풀이
이렇게 풀었을 때 n이 커지더라도 상수 시간으로 값을 구할 수 있다.
1. 현재 꽉 채운 상자 라인의 수 - 내가 찾는 상자의 줄 번호 + 1
2. 나머지 상자들로 만들어진 라인으로 한 번 더 추가해야하는지 구분한다.

+ 현재 꽉 채운 상자 라인의 수를 구한다. `line`
+ 내가 찾는 상자의 줄 번호를 구한다. `num_line`
+ 상자의 번호와 라인의 번호로 알맞은 위치를 구한다. `my_box_idx, extra_box_idx`
+ 여분 상자 라인의 번호에 유의하여 인덱스를 비교해 상자가 하나 더 쌓였는지 확인한다.
	+ 짝수면 내림차순 extra_box_idx <= my_box_idx
	+ 홀수면 오름차순 `extra_box_idx >= my_box_idx`


## 코드
```cpp
#include <string>
#include <vector>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    vector<vector<int>> boxes = vector<vector<int>>(w, vector<int>());
    int i = 1;
    int idx = 0;
    int idy = 0;
    while(i <= n)
    {
        for(int j = 0; j < w && i <= n; j++)
        {
            if(num == i)
            {
                idx = j;
                idy = boxes[j].size();
            }
            boxes[j].push_back(i++);
        }
        for(int j = w-1; j >= 0&&i <= n; j--)
        {
            if(num == i)
            {
                idx = j;
                idy = boxes[j].size();
            }
            boxes[j].push_back(i++);
        }
    }
    answer = boxes[idx].size() - idy;
    return answer;
}
```
```cpp title='다른 풀이'
#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
		//complete line
    int line = n/w;
    // num's line
    int num_line = 1 + (num-1)/w;
    answer = line - num_line + 1;
    //process: extra line
		int my_box_idx = num_line%2 == 0 ? (w-1) - (num-1)%w: (num-1)%w;
    int extra_box_idx = (line+1)%2 == 0 ? (w-1) - (n-1)%w: (n-1)%w;
    if(line*w < n)
    {
       switch((line+1)%2)
       {
           case 0:
               if(extra_box_idx <= my_box_idx)answer++;
               break;
           case 1:
               if(extra_box_idx >= my_box_idx)answer++;
               break;
       }
    }
       
    return answer;
}
```
%%
```cpp title='다른 분의 풀이'
#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    while(num<=n)
		{
			answer++;
			num+=(w-1-(w+num-1)%w)*2+1;
		}
    return answer;
}
```
%%