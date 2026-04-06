# [노란불 신호등](https://school.programmers.co.kr/learn/courses/30/lessons/468371)
## 풀이
노란불이 겹쳐질 때의 시간을 구하여라.
+ 5가지 신호의 최악의 경우(단순하게 계산) `1,860,480`
+ 모든 신호 주기의 최소 공배수를 구하여 연산의 한계량을 구하여 최악의 경우보단 적게 함 `max`
+ 각 사이클 중의 모든 신호가 Y인 경우 해당 시간을 반환하여야 한다.
	+ 각 신호들의 GYR 리스트를 만든다.
+ 시각을 증가시키면서 해당 시각에 모든 신호들이 `Y`인지 검사하여 모두 `Y`라면 반복을 그만하고 해당 시각 + 1(0부터 시작하기 때문에 1을 더함) 해서 값을 반환한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
long long gcd(long long a, long long b)
{
    long long r;
    while(r != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
long long lcm(long long a, long long b){
    return (a*b)/gcd(a,b);
}
int solution(vector<vector<int>> signals) {
    int answer = -1;
    vector<vector<char>> signal_list;
    int max = 1;

		//init: GYR list
    for(vector<int> signal : signals)
    {
        vector<char> list;
        for(int i=0;i<signal[0];i++)list.push_back('G');
        for(int i=0;i<signal[1];i++)list.push_back('Y');
        for(int i=0;i<signal[2];i++)list.push_back('R');
        signal_list.push_back(list);
        max = lcm(max, list.size());
    }

		//process: 시간을 올리며 신호가 겹치는지 계산
    for(int time=0; time < max; time++)
    {
        int cnt = 0;
        for(int i=0; i<signal_list.size(); i++)
        {
            if(signal_list[i][time%signal_list[i].size()] == 'Y')cnt++;
        }
        if(cnt == signal_list.size())
        {
            answer = time+1;
            break;
        }
    }
    return answer;
}
```
