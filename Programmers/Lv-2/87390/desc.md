# [n^2 배열 자르기](https://school.programmers.co.kr/learn/courses/30/lessons/87390)
## 풀이
- 1 2 3
- 2 2 3 
- 3 3 3
- 위의 형태를 생각해보면 행과 열 값 중에 큰값이 해당 위치의 값이 됨
### case1
+ 1차원 배열의 인덱스를 n*n 형태의 2차원 배열의 인덱스로 변환하여 값을 추출함
+ 행과 열 중에 값이 가장 큰 값이 해당 순번에 들어가야할 값임
+ 다루는 게 4바이트 int형이라 의외로 빠름

### case2
+ case1과 동일한 구상
+ 1차원 배열의 인덱스를 2차원 배열의 인덱스로 변환하지만 long long으로 변환하여 코드를 간결하게 구성함

## 코드
```cpp title='long long 범주에서 int 범주로'
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 1 2 3
// 2 2 3
// 3 3 3
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int num = 1;
    int startRow  = left/n;
    int startColumn = left%n;
    
    int endRow = right/n;
    int endColumn = right%n;
    
    int start = startColumn;
    int end = n-1;
    for(int i = startRow; i <= endRow; i++)
    {
        if(i==endRow) end = endColumn;
        if(i!=startRow) start = 0;
        for(int j = start; j <= end; j++)
        {
            answer.push_back(max(i,j) + 1);
        }
    }
    return answer;
}
```

```cpp title='long long 범주'
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 1 2 3
// 2 2 3
// 3 3 3
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long row, col;
    for(long long i = left; i <= right; i++)
    {
        row = i/n;
        col = i%n;
        answer.push_back(max(row,col)+1);
    }
    return answer;
}
```