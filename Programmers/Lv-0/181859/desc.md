# [배열 만들기 6](https://school.programmers.co.kr/learn/courses/30/lessons/181859)
## 풀이
문제에서 설명하는 내용을 그대로 코드로 구현한다.

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for(int i=0; i<arr.size(); i++)
    {
        if(answer.size() == 0)answer.push_back(arr[i]);
        else if(answer[answer.size()-1] == arr[i])answer.erase(answer.begin()+answer.size()-1);
        else
        {
            answer.push_back(arr[i]);
        }
    }
    if(answer.size()==0)answer.push_back(-1);
    return answer;
}
```
