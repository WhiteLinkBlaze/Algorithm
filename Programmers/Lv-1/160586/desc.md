# [대충 만든 자판](https://school.programmers.co.kr/learn/courses/30/lessons/160586)
## 풀이
처음에 모든 값을 순회하고, 특정 문자에 대한 최소 값을 맵핑해둔다.
+ 목표로하는 문자열이 나온다면 맵핑된 내용을 참조하여 결과를 구성한다.
## 코드
```cpp
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> key_map;
    //init
    for(auto& key : keymap)
    {
        for(int j = 0; j<key.length(); j++)
        {
            if(key_map[key[j]] == 0 || j + 1 < key_map[key[j]]) key_map[key[j]] = j+1;
        }
    }
    //process
    for(auto& target_key : targets)
    {
        int sum = 0;
        for(int i = 0; i < target_key.length(); i++)
        {
            if(key_map[target_key[i]] == 0)
            {
                sum = -1;
                break;
            }
            sum += key_map[target_key[i]];
        }
        answer.push_back(sum);
    }
    return answer;
}
```
