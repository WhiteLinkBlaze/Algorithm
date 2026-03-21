# [소수 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/12977)
## 풀이
주어진 리스트에서 숫자 3개를 뽑아 더했을 때 소수가 되는 조합들의 개수를 카운트하는 문제임
+ 조합을 만들기 위해 n개 뽑기 때문에 n중첩 반복문
+ 소수 판별을 위한 is_prime을 통해 소수인 경우에만 answer를 증가시켰다.
## 코드
```cpp
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
bool is_prime(const int& num)
{
    bool result = true;
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num%i == 0)return false;
    }
    return result;
}
int solution(vector<int> nums) {
    int answer = 0;
    int len = nums.size();
    //n^3??
    for(int i = 0; i < len-2; i++)
    {
        for(int j = i+1; j<len-1; j++)
        {
            for(int k = j+1; k<len; k++)
            {
                if(is_prime(nums[i] + nums[j] + nums[k]))answer++;
            }
        }
    }
    return answer;
}
```