# [무작위로 K개의 수 뽑기](https://school.programmers.co.kr/learn/courses/30/lessons/181858)
## 풀이
정수 배열 arr이 주어지는데 정렬 된다고 하지 않았기에 checkList 배열을 미리 만들어 기록용으로 사용한다.
+ 탐색을 진행하는데 checkList 안에 없는 내용일 경우에만 answer에 집어 넣는다.
+ answer에 값을 다 넣었지만 개수가 부족하다면 k개가 될 때까지 -1을 집어넣는다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    bool checkList[100001] = {false,};
    for(int i = 0; i < arr.size() && answer.size() < k; i++)
    {
        if(!checkList[arr[i]])
        {
            answer.push_back(arr[i]);
            checkList[arr[i]] = true;
        }
    }
    while(answer.size() < k)
    {
        answer.push_back(-1);
    }
    return answer;
}
```