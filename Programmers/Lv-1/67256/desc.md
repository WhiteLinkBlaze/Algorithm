# [[카카오 인턴] 키패드 누르기](https://school.programmers.co.kr/learn/courses/30/lessons/67256)
## 풀이
1. 1,4,7은 왼손으로 누른다.
2. 3,6,9는 오른손으로 누른다.
3. 0,2,5,8은 가까운 손가락으로 누른다. 거리가 같다면 주로 쓰는 손으로 누른다.

3번을 해결하기 위해 필요한 것
1. 키패드 배열을 만들고 해당 숫자의 좌표값을 기록(`keypad`)
2. 각 손이 이전에 누른 위치 (`left[2], right[2]`)
3. 누르려는 키의 위치와의 각 손과의 거리(`distance_to_left, distance_to_right`)
3번의 해당하는 경우 각 손과의 거리를 구함
+ 거리가 같음 -> 주로 사용하는 손으로 누르고 손의 위치를 갱신
+ 거리가 가까운 것 -> 가까운 손에 해당하는 손으로 누르고 손의 위치를 갱신
## 코드
```cpp
#include <string>
#include <vector>
using namespace std;
char pushButton(int * hand, const vector<pair<int,int>> &keypad, const int target, const char LR)
{
    hand[0] = keypad[target].first;
    hand[1] = keypad[target].second;
    return LR;
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int,int>> keypad;
    int left[2] = {0,3};
    int right[2] = {2,3};
    
    //init keypad
    keypad.push_back(make_pair(1,3));
    for(int y=0; y<3; y++)
    {
        for(int x=0; x<3; x++)
        {
            keypad.push_back(make_pair(x,y));
        }
    }
    //process
    for(int target : numbers)
    {
        bool is_left = target%3==1;
        bool is_right = target != 0 && target%3 == 0;
        
        if(is_left)
            answer+=pushButton(left, keypad, target, 'L');
        else if(is_right)
            answer+=pushButton(right, keypad, target, 'R');
        else
        {
            int distance_to_left = abs(keypad[target].first-left[0]) + abs(keypad[target].second-left[1]);
            int distance_to_right = abs(keypad[target].first-right[0]) + abs(keypad[target].second-right[1]);
            if(distance_to_left == distance_to_right)
            {
                switch(hand[0])
                {
                    case 'l':
                        answer += pushButton(left, keypad, target, 'L');
                        break;
                    case 'r':
                        answer += pushButton(right, keypad, target, 'R');
                        break;
                }
            }
            else if(distance_to_left < distance_to_right)
                answer += pushButton(left, keypad, target, 'L');
            else
                answer += pushButton(right, keypad, target, 'R');
        }
    }
    
    
    return answer;
}
```
