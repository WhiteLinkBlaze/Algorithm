# [로또의 최고 순위와 최저 순위](https://school.programmers.co.kr/learn/courses/30/lessons/77484)
## 풀이
주어진 로또 번호와 당첨 번호를 통해 될 수 있는 최고 당첨 순위와 최저 당첨 순위를 반환하는 것
+ 로또 번호에는 0이 있는데 이는 맞춘 것도 될 수 있고 못맞춘 것도 될 수 있다.
+ 당첨 번호는 고정된 길이이므로 46까지의 배열을 생성하고, 당첨번호를 기록한다. 당첨 번호이면 해당 요소의 값은 1이다.
+ 내 로또 번호를 당첨 번호 배열에서 검색해서 체크한다.
	+ 같은 숫자가 있다면 cnt++
	+ 내 숫자가 0이면 blank_cnt++
+ 최고의 등수는 맞춘 개수가 cnt+blank_cnt일 때 최고의 등수이다.
+ 최저의 등수는 맞춘 개수가 cnt개 일 때가 최저의 등수이다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
int get_rank(int cnt)
{
    int result = 7 - cnt;
    if(cnt == 0)return 6;
    return result;
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int numbers[46] = {0,};
    int cnt = 0;
    int blank_cnt = 0;
    for(int i : win_nums)
    {
        numbers[i] = 1;
    }
    
    for(int i : lottos)
    {
        if(i!=0 && numbers[i])cnt++;
        if(i==0)blank_cnt++;
    }
    //best
    answer.push_back(get_rank(blank_cnt + cnt));
    //worst
    answer.push_back(get_rank(cnt));
    return answer;
}
```
