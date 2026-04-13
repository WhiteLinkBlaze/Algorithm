# [명예의 전당 (1)](https://school.programmers.co.kr/learn/courses/30/lessons/138477)
## 풀이
+ 상위 k번째 이내이면 해당 가수의 점수를 명예의 전당이라는 목록에 올려 기념합니다.
+ k번째 순위의 가수 점수보다 더 높으면, 출연 가수의 점수가 명예의 전당에 오르게 되고 기존의 k번째 순위의 점수는 명예의 전당에서 내려오게 됩니다.
+ 매일 발표된 명예의 전당의 최하위 점수를 return하는 solution 함수를 완성해주세요.

heap 구조를 이용해서 풀이
+ min heap의 경우 최솟값이 루트 노드로 올라오게 되어 새로운 전당 입성자가 나왔을 때 교체하기 용이하다.
+ 최솟값을 `answer`에 기록하기 때문에 루트 노드의 값만 기록하면 된다.
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> temple;
    make_heap(temple.begin(), temple.end(),std::greater<int>());
    for(int i = 0; i < score.size(); i++)
    {
        if(i < k)
        {
            temple.push_back(score[i]);
            push_heap(temple.begin(), temple.end(),std::greater<int>());
        }
        else if(temple.front() < score[i])
        {
            pop_heap(temple.begin(), temple.end(),std::greater<int>());
            temple.pop_back();
            temple.push_back(score[i]);
            push_heap(temple.begin(), temple.end(),std::greater<int>());
        }
        answer.push_back(temple.front());
    }
    return answer;
}
```