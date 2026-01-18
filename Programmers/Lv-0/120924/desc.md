# [다음에 올 숫자](https://school.programmers.co.kr/learn/courses/30/lessons/120924)
## 용어
+ arithmetic progression
+ geometric progression
+ 공차(common difference)
+ 공비(common ratio)
## 풀이

### 등차수열
> [!note] 
[수학](https://ko.wikipedia.org/wiki/%EC%88%98%ED%95%99)에서 **등차수열**(等差數列, [문화어](https://ko.wikipedia.org/wiki/%EB%AC%B8%ED%99%94%EC%96%B4 "문화어"): 같은차수렬, [영어](https://ko.wikipedia.org/wiki/%EC%98%81%EC%96%B4 "영어"): arithmetic progression, **AP** 또는 arithmetic sequence)은 연속하는 두 항의 차이가 모두 일정한 [수열](https://ko.wikipedia.org/wiki/%EC%88%98%EC%97%B4 "수열")을 뜻한다. 예를 들어 1, 3, 5, 7, 9, ...은 등차수열이다. 이때 두 항의 차이는 이 수열의 모든 연속하는 두 항들에 대해서 **공**통으로 나타나는 **차**이므로, **공차**(common difference)라고 한다. 예를 들어, 앞의 수열의 공차는 2이다.

수열의 첫항을 a1, 공차를 d라고 할 때, 일반항을 다음과 같이 나타낼 수 있다.
$$
a_n = a_1 + (n-1)d
$$
따라서 d를 구하려면 아래와 같이 구할 수 있다.
$$
d = a_n - a_{n-1}
$$
### 등비수열
> [!note] 
**등비수열**(等比數列, [문화어](https://ko.wikipedia.org/wiki/%EB%AC%B8%ED%99%94%EC%96%B4 "문화어"): 같은비수렬, [영어](https://ko.wikipedia.org/wiki/%EC%98%81%EC%96%B4 "영어"): geometric sequence) 또는 **기하수열**(幾何數列)은 각 항이 이전 항과 일정한 비를 가지는 [수열](https://ko.wikipedia.org/wiki/%EC%88%98%EC%97%B4 "수열")을 말하며, 각 항과 이전 항의 일정한 비율을 **공비**(共比, common ratio)라고 한다.

초항이 a이고 공비가 r인 등비수열은 다음과 같다.
$$
a,ar,ar^2,ar^3,...
$$
공비를 구하려면 아래와 같이 구할 수 있다.
$$
r = ar^{n}/ar^{n-1}
$$

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int size = common.size();
    int a = common[0];
    int arith_D = common[1]-a;
    int geo_D = common[1];
    if(a == 0) return common[size-1]+arith_D;
    else geo_D /= a;
    //arithmetic or geometric
    answer = (a + 2*arith_D == common[2]) ? (common[size-1]+arith_D) : (common[size-1]*geo_D);
    return answer;
}
```

## 참고 자료
+ [등비수열](https://ko.wikipedia.org/wiki/등비수열)
+ [등차수열](https://ko.wikipedia.org/wiki/등차수열)