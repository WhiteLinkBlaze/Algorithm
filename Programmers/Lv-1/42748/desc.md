# [K번째수](https://school.programmers.co.kr/learn/courses/30/lessons/42748)
## 풀이
+ 특정 구간의 수를 정렬하고 정렬한 수들 중 k번째에 해당하는 값을 추출하라.

1. 특정 구간을 추출
2. 추출한 배열을 정렬
3. k번째 수 추출

+ 위 과정을 여러번 해야하기에 vector나 변수들을 반복문 외부에서 선언
## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int start, end, k;
    vector<int> subArray;
    vector<int> ::iterator it;
    for(vector<int> command : commands)
    {
        start = command[0]-1;
        end = command[1];
        k = command[2]-1;
				//특정 구간을 추출
        for(it = array.begin()+start; it<array.begin()+end; it++) subArray.emplace_back(*it);
				//추출한 배열을 정렬
        sort(subArray.begin(), subArray.end());
				//k번째 수 추출
        answer.push_back(subArray[k]);
        subArray.clear();
    }
    return answer;
}
```