# [중요한 단어를 스포 방지](https://school.programmers.co.kr/learn/courses/30/lessons/468370)
## 풀이
> 당신은 메시지 시작부터 왼쪽 → 오른쪽 순서로 스포 방지 구간을 하나씩 클릭해 공개되는 단어들 중, 중요한 단어가 몇 개인지 확인하려 합니다.
+ 스포 방지 단어여야 합니다.
+ 메시지의 스포 방지 구간이 아닌 구간(= 어떤 스포 방지 구간에도 속하지 않는 모든 구간: 각 구간의 앞·사이·뒤 포함)에 등장한 적이 없어야 합니다.
+ 이전에 공개된 스포 방지 단어와 중복되지 않아야 합니다.
+ 여러 단어가 동시에 공개된 경우, 왼쪽부터 순서대로 하나씩 중요한 단어인지 판단합니다.

스포 방지를 위해 마스킹할 범위를 제공해주는데 range를 그대로 사용하기에는 복잡할 것 같았다. 그래서 마스킹 처리한 문장을 새로 구성하여 그것을 통해 맨 위부터 하나씩 열어보자! 라는 아이디어로 시작하였다.
+ 메시지 시작부터 왼쪽 -> 오른쪽 순서로 스포 방지 구간을 하나씩 클릭한다는 조건이 있다.
+ 마스킹할 구간에는 여러 단어가 포함될 수 있었다. 공백을 제외하고 나머지는 마스킹한다.
+ 이렇게 마스킹한 문자열 `masked_msg`

스포일러 방지를 위한 구간을 생각해보니`may i`의 case를 보고 문자열 자체에서 찾는 건 좋은 선택이 아니었다. 
+ `i`의 경우 때문인데 단어 내에 `i`만 들어가도 찾았다! 가 되어버린다. 그래서 문장을 단어 단위로 분리했다. 그것이 `origin_words`와 `masked_words`이다.
+ 공백을 기준으로`message`를 `split`, `masked_msg`를 `split`하여 `origin_words`와 `masked_words`를 구성한다.

`origin_words`와 `masked_words`을 서로 비교하여 다른 경우 -> 마스킹한 경우
+ 해당 단어가 앞서 나온적이 있는지 확인한다. (`origin_words`에서 찾는다.)
+ 해당 단어가 이후에 나온적이 있는지 확인한다. (`masked_words`에서 찾는다.)
+ 위 두 조건 모두 나온적이 없다면 중요한 단어 목록(`important_list`)에 포함시킨다.
### set를 이용
+ set를 이용할 때 masked_words에서 단어들을 미리 삽입한다.
+ 원본 메시지에서 단어를 추출해서 set에서 개수를 확인한다.
	+ 0개인 경우가 스포 방지 처리가 되어서 가려진 단어임 혹은 아직 안 나왔던 단어이다.
	+ 안 나왔던 단어는 다시 세트에 넣어서 중복을 제외한다.
	+ `important_list`에 추가
+ 모든 과정 끝나고 answer에 개수 저장

### 기록
분명 아이디어는 보자마자 생각났는데 코드로 나타내는 과정이 쉽지 않았다. 뭘 고민 했었던건지 기억이 안 난다..

## 코드
```cpp
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;
void print_vector(vector<string>& list)
{
    for(string& str : list)cout<<str<<endl;
}
vector<string> splitString(const string& str, char delimiter) 
{
    vector<string> ret;
    string token;
    stringstream ss(str);
    while (getline(ss, token, delimiter)) 
  	{
        ret.push_back(token);
    }
    return ret;
}

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    string masked_msg = message;
    vector<string> origin_words = splitString(message, ' ');
    vector<string> masked_words;
    //init masked_msg
    for(vector<int>& spoiler_range: spoiler_ranges)
    {
        int start = spoiler_range[0];
        int end = spoiler_range[1];
        
        //마스킹 처리
        for(int i = start; i <= end; i++)
        {
            if(message[i] == ' ')continue;
            masked_msg[i] = '*';
        }
    }
    masked_words = splitString(masked_msg, ' ');
    vector<string> important_list;
    //process
    auto start = origin_words.begin();
    auto masked_end = masked_words.end();
    for(int idx = 0; idx < origin_words.size(); idx++)
    {
        if(origin_words[idx].compare(masked_words[idx]) != 0)//마스킹된 단어인데
        {
            //이전에 등장 했나요? -> 아니요일 경우 실행
            if(find(start, start+idx,origin_words[idx]) == start+idx
              && find(masked_words.begin()+idx, masked_end, origin_words[idx]) == masked_end)
            {
                important_list.push_back(origin_words[idx]);
            }
        }
    }
    answer = important_list.size();
    return answer;
}
```

```cpp title='다른 분 풀이 참고해서 수정함'
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
void print_vector(vector<string>& list)
{
    for(string& str : list)cout<<str<<endl;
}
vector<string> splitString(const string& str, char delimiter) 
{
    vector<string> ret;
    string token;
    stringstream ss(str);
    while (getline(ss, token, delimiter)) 
  	{
        ret.push_back(token);
    }
    return ret;
}
int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    string masked_msg = message;
    vector<string> origin_words = splitString(message, ' ');
    vector<string> masked_words;
    set<string> s;
    //init masked_msg
    for(vector<int>& spoiler_range: spoiler_ranges)
    {
        int start = spoiler_range[0];
        int end = spoiler_range[1];
        for(int i = start; i <= end; i++)
        {
            if(message[i] == ' ')continue;
            masked_msg[i] = '*';
        }
    }
    masked_words = splitString(masked_msg, ' ');
    vector<string> important_list;
		//init set
    for(string& word : masked_words)
        s.insert(word);
		//process important_list    
    for(string word: origin_words)
    {
        if(s.count(word) == 0)
        {
            important_list.push_back(word);
            s.insert(word);
        }
    }
    answer = important_list.size();
    return answer;
}


```