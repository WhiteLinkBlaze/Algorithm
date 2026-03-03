# [가장 많이 받은 선물](https://school.programmers.co.kr/learn/courses/30/lessons/258712)
## 풀이
+ a가 b에게 5회 선물을 주고, b가 a에게 3회 주었다면 다음에는 b 가 a에게 선물을 한 번 줘야한다.
+ 주고 받은 수가 같다면
	+ 선물 지수가 더 큰 사람이 더 작은 사람에게 받는다.
	+ 선물 지수: 이번달까지 자신이 친구들에게 준 선물의 수에서 받은 선물의 수를 뺀 값

가장 선물을 많이 받을 친구가 받을 선물의 수를 구하여라

### 미리 구성한 것
+ `friends_idx`:이름-index 맵
+ `p_value`: 선물 지수
+ `snd_rec`: 주고 받은 기록 테이블
#### process: gift log
+ send가 receive에게 선물을 주다.
+ `snd_rec[send][receive]++;`
+ `p_value[send]++`:send가 선물을 주었으므로, send의 선물 지수 상승
+ `p_value[receive]--;`: receive가 선물을 받았으므로, receive의 선물 지수 하락

#### process: receive gift, next month
친구가 다음달에 받을 선물을 기록함, 가장 많이 받을 친구가 받을 선물의 개수이므로 최댓값만 구하면 된다.
+ `name`이 `n_friend`에게 받는지 확인하고 받으면 `cnt++`
+ `name`이 받으려면
	+ `n_friend`가 준 것보다 많이 줬거나
	+ 주고 받은 횟수가 같은데, `n_friend`보다 선물 지수`p_value`가 높아야 한다.
+ 구한 `cnt`가 최댓값을 넘었으면 최댓값을 갱신한다.

```cpp
int max = 0;
for(const auto & [name, idx]: friends_idx)
{
		int cnt = 0;
		for(string n_friend: friends)
		{
				int nf_idx = friends_idx[n_friend];
				if(n_friend.compare(name) == 0)
						continue;
				if(snd_rec[idx][nf_idx] - snd_rec[nf_idx][idx] > 0)
						cnt++;
				else if(snd_rec[idx][nf_idx] - snd_rec[nf_idx][idx] == 0 && p_value[idx] > p_value[nf_idx])
						cnt++;
		}
		if(max < cnt) max = cnt;
}
```

## 코드
```cpp
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> friends_idx;
    int n = friends.size();
    vector<int> p_value(n,0);
    vector<vector<int>> snd_rec(n, vector<int>(n,0));
    
    // init map
    for(int i=0; i<friends.size(); i++)friends_idx[friends[i]] = i;
    
    // process: gift log
    for(string log : gifts)
    {
        stringstream in(log);
        string a,b; in>>a>>b;
        int send = friends_idx[a];
        int receive = friends_idx[b];
        snd_rec[send][receive]++;
        p_value[send]++;
        p_value[receive]--;
    }
    
    // process: receive gift, next month
    int max = 0;
    for(const auto & [name, idx]: friends_idx)
    {
        int cnt = 0;
        for(string n_friend: friends)
        {
            int nf_idx = friends_idx[n_friend];
            if(n_friend.compare(name) == 0)
                continue;
            if(snd_rec[idx][nf_idx] - snd_rec[nf_idx][idx] > 0)
                cnt++;
            else if(snd_rec[idx][nf_idx] - snd_rec[nf_idx][idx] == 0 && p_value[idx] > p_value[nf_idx])
                cnt++;
        }
        if(max < cnt) max = cnt;
    }
    answer = max;
    return answer;
}
```
