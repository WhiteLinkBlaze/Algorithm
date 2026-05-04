# [N개의 최소 공배수](https://school.programmers.co.kr/learn/courses/30/lessons/12953)

## 풀이

## 코드
```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
    int r = 1;
    while(r)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int solution(vector<int> arr) {
    int answer = arr.back();
    sort(arr.begin(), arr.end(), greater<int>());
    for(auto& num : arr)
    {
        answer = (num * answer)/gcd(num, answer);
    }
    return answer;
}
```