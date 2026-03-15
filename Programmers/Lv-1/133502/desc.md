# [햄버거 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/133502)
## 풀이
처음 쓴 풀이는 이렇다.
+ 햄버거를 만드는데 2,1,1,2,3,1,2,3,1 일 때 세 번째에서 일곱 번째가 사용되면, 해당 숫자는 없는 취급을 해야함
+ 그래서 처음 풀이에서는 erase로 지웠었으나, 길이를 보니 1,000,000인 것이다. 너무 많은 양이므로 속도가 좋지 못했다.
+ 0으로 바꾸는 방법으로 바꾸고, 1을 만났을 때 역순으로 4개를 체크한다.
	+ 체크하는 중에 0을 만나면 0은 무시하고 체크횟수는 줄지 않는다.
+ 체크를 성공적으로 시행했다면, 지나왔던 모든 숫자를 0으로 바꾼다.

깔끔한 다른 사람의 풀이는 이렇다
+ 1을 만났다면 이번 회차에 본게 2인 경우 12를 묶어서 마지막 요소를 갱신한다.
+ 그 다음으로 3을 만났다면 123으로 묶어서 갱신한다.
+ 그 다음으로 1을 만났다면 answer를 증가시키고 123을 빼어 요소에서 제외한다.
깔끔하고 좋은 방법이다.
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    for(int idx = 0; idx < ingredient.size(); idx++)
    {
        if(idx >= 3 && ingredient[idx] == 1)
        {
            int cnt = 3;
            int i = idx-1;
            while(i >= 0 && cnt)
            {
                if(ingredient[i] == 0) cnt++;
                else if(ingredient[i] != cnt) break;
                i--;
                cnt--;
            }
            if(cnt == 0)
            {
                for(int j = idx; j > i; j--)ingredient[j]=0;
                answer++;
            }
        }
    }
    return answer;
}
```
```cpp title='깔끔한 다른사람의 풀이'
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = { -1 };
    for(int x : ingredient){
        if(v.back() == 1 && x == 2) v.back() = 12;
        else if(v.back() == 12 && x == 3) v.back() = 123;
        else if(v.back() == 123 && x == 1) answer++, v.pop_back();
        else v.push_back(x);
    }    

    return answer;
}
```
