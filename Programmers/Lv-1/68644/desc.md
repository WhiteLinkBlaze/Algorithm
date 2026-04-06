# [두 개 뽑아서 더하기](https://school.programmers.co.kr/learn/courses/30/lessons/68644)
## 풀이
+ 2개를 뽑아서 더한 결과를 중복을 제거한 정렬된 리스트의 형태로 반환해야함
+ 이를 위해 set를 사용하여 중복을 제거하고, 정렬됨(정렬하지 않으려면, unordered_set라고 따로 있음)
+ 구성한 set에서 내용을 뽑아 결과에 기록하여 반환
## 코드
```cpp
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
    for(int i=0; i < numbers.size()-1; i++)
    {
        for(int j=i+1; j < numbers.size(); j++)
        {
            s.insert(numbers[i] + numbers[j]);
        }
    }
    answer.assign(s.begin(), s.end());
    return answer;
}
```
