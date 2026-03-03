# [[PCCP 기출문제] 1번 / 붕대 감기](https://school.programmers.co.kr/learn/courses/30/lessons/250137)
## 풀이
구현문제임

시간을 기준으로 반복을 진행한다. (0 -> attacks의 마지막 공격까지)
+ 공격을 받는 순간이면 cur_health가 깍이고, heal_cnt 초기화 되고, cur_health가 0 이하면 죽는다. -1을 cur_health에 저장한다.
+ 공격을 받는 순간이 아닌 경우 붕대 감기가 적용될 수 있는 순간들이다.
	+ 최대 health보다 작다면 회복
	+ 회복을 한 횟수가 조건에 맞다면 추가 회복
+ answer 에 cur_health를 저장하고 반환한다.
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int time = 0;
    int heal_cnt = 0;
    int cur_health = health;
    int end_time = attacks.back()[0];
    int atk_cnt = 0;
    while(time <= end_time)
    {
        int atk_time = attacks[atk_cnt][0];
        int atk_damage = attacks[atk_cnt][1];
        if(time == atk_time)
        {
            cur_health -= atk_damage;
            atk_cnt++;
            heal_cnt = 0;
            if(cur_health <= 0)
            {
                cur_health = -1;
                break;
            }
        }
        else
        {
						//bandage
            if(cur_health < health)
            {
                cur_health = (cur_health + bandage[1]) > health ? health : (cur_health + bandage[1]);
                heal_cnt++;
            }
            if(heal_cnt == bandage[0])   
            {
                cur_health = (cur_health + bandage[2]) > health ? health : (cur_health + bandage[2]);
                heal_cnt = 0;
            }
        }
        time++;
    }
    answer = cur_health;
    return answer;
}
```
%%
```cpp title='인상적이었던 코드'
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int maxhealth = health, time = 0;
    for(int i=0;i<attacks.size();i++){
        int dTime = attacks[i][0];
        int damage=attacks[i][1];
        int diff = dTime - time-1;
        health += diff*bandage[1] +diff/bandage[0] * bandage[2];
        if(health > maxhealth) health = maxhealth;
        health-=damage;
        time = dTime;
        if(health<=0) break;
    }
    return health<=0 ? -1:health;
}
```
%%