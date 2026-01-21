# [최빈값 구하기](https://school.programmers.co.kr/learn/courses/30/lessons/120812)
## 풀이
+ 가장 많이 나온 숫자를 반환하면 되는데, 같은 횟수로 나온 게 있다면 -1을 반환해야한다.
+ 1000까지의 숫자가 나오므로 array내의 숫자중 가장 큰 숫자를 기록해서 탐색 횟수를 줄인다.
	+ 정렬돼서 제공해 준다는 말이 없었다.
+ array를 탐색하며 나온숫자들을 1001칸의 배열 memo에 횟수를 기록하고 다 기록했다면 1부터 maxIndex까지 탐색하여 값을 반환한다. 이때 같은 값이 있었다면 -1을 반환한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int memo[1001] = {0,};
    int maxCountIndex = 0;
    int maxIndex = 0;
    int check = true;
    for(int num : array)
    {
        memo[num]++;
        if(maxIndex < num)
            maxIndex = num;
        if(memo[maxCountIndex] < memo[num]) 
        {
            maxCountIndex = num;
        }
    }
    for(int i=1;i<=maxIndex;i++)
    {
        if(maxCountIndex!=i && memo[maxCountIndex]==memo[i])
        {
            check = false;
            break;
        }
    }
    answer = check?maxCountIndex:-1;
    return answer;
}
```