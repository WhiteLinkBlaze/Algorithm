# [배열 조각하기](https://school.programmers.co.kr/learn/courses/30/lessons/181893)
### code1
+ query의 내용을 탐색하면서 바로바로 배열에 반영하는 방식이다.
+ 메모리가 변경되는 경우가 잦아서 오래걸릴 수 있다.
### code2
+ query의 내용을 탐색하면서 완성될 배열의 구역을 구성하는 방식이다.
+ query는 적용한 내용을 토대로 다음 인덱스를 주기 때문에 주의해야한다.
+ `end = start + query[i];` 
	+ end는 시작점을 기준으로 index를 구성하게 되므로, start+요구하는 인덱스로 새로이 설정한다.
+ `start += query[i];`
	+ start는 0 + distance 의 형태, 이는 start+ start+distance ... 같은 형태가 된다.
+ 구간을 구성한 것을 토대로 answer에 arr의 내용을 구간만 분리해서 구성한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    for(int i=0;i<query.size();i++)
    {
        vector<int>::iterator start,end;
        if(i%2 == 0)
        {
            start = arr.begin() + query[i] + 1;
            end = arr.begin() + arr.size();
        }
        else
        {
            start = arr.begin();
            end = arr.begin()+query[i];
        }
        arr.erase(start,end);
    }
    answer = arr;
    return answer;
}
```
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    int start = 0;
    int end = 0;
    
    for(int i=0;i<query.size();i++)
    {
        if(i%2==0)
            end = start + query[i];
        else
            start += query[i];
    }
    answer = vector<int>(arr.begin()+start, arr.begin()+end+1);
    
    return answer;
}
```