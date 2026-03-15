# [바탕화면 정리](https://school.programmers.co.kr/learn/courses/30/lessons/161990)
## 풀이
+ 정답을 구성하기 위해 필요한 것은 좌상단(최소 y, 최소 x)과 우하단(최대 y, 최대 x)가 필요하다.
+ 주어진 리스트를 탐색하면서 `#`을 만나면 최소 좌표와 최대 좌표를 구성하여 반환한다.
## 코드
```cpp title='깔끔함'
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {999,999,0,0};
    
    for(int i =0; i < wallpaper.size(); i++)
    {
        for(int j =0; j < wallpaper[i].length(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                answer[0] = min(answer[0], i);
                answer[1] = min(answer[1], j);
                answer[2] = max(answer[2], i+1);
                answer[3] = max(answer[3], j+1);
            }
        }
    }
    return answer;
}
```
```cpp title='처음 푼 풀이'
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux=50, luy=50;
    int rdx=0, rdy=0;
    
    for(size_t i =0; i < wallpaper.size(); i++)
    {
        for(size_t j =0; j < wallpaper[i].length(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(i+1 > rdy)rdy = i+1;
                if(i < luy)luy = i;
                if(j+1 > rdx)rdx = j+1;
                if(j < lux)lux = j;
            }
        }
    }
    
    answer.push_back(luy);
    answer.push_back(lux);
    answer.push_back(rdy);
    answer.push_back(rdx);
    
    return answer;
}
```