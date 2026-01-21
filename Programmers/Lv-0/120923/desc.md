# [연속된 수의 합](https://school.programmers.co.kr/learn/courses/30/lessons/120923)
## 풀이
+ 등차수열의 합 공식을 사용하는 문제임
### solve1
+ 등차수열의 합 공식을 이용하여 풀었다.
+ num은 개수
$$
total = (start + last)*num/2
$$
+ last 값
$$
last = start + d(num-1)
$$
+ start 값은 
$$
start = \frac{total}{num}-\frac{num-1}{2}
$$
+ 따라서 start ~start+num까지의 값들을 구해서 반환하면된다.
### solve2
+ 슬라이딩 윈도우 구조가 먼저 생각나서 이렇게 풀었다.
+ 시간이 오래걸리는 구간이 있다. (1초 이상)
+ sum을 통해 윈도우를 구성하고 여기서 1을 빼거나 더하면 윈도우는 양 옆으로 움직이는 것처럼 된다.
+ 답 중에 음수를 포함하는 값이 있어서 큰 수에서 작은 수로 맞춰가는 형태로 구현한다.
+ init sum: 슬라이딩 윈도우를 구성
+ process: 해당 윈도우가 total에 맞을 때까지 이동
+ set answer: 해당 윈도우의 앞자리 값으로 answer를 구성한다.
## 코드
```cpp title='commondiff'
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int start = total/num - (num-1)/2;
    for(int i=start;i<start+num;i++)
        answer.push_back(i);
    
    return answer;
}
```
```cpp title='sliding window'
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int sum = 0;
    int curNum = (total+num-1)/2;
    //init sum
    for(int i = 0; i < num; i++)
    {       
        sum += curNum;
        curNum--;
    }
    //process
    while(sum!=total)
    {
        sum-=(curNum+num);
        sum+=curNum;
        curNum--;
    }
    curNum++;
    //set answer
    for(int i=curNum;i<curNum+num;i++)
        answer.push_back(i);
    
    return answer;
}
```