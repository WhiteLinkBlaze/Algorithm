# [영어가 싫어요](https://school.programmers.co.kr/learn/courses/30/lessons/120894)
## 풀이
문자들이 공백 없이 붙어서 나오기 때문에 시작 지점부터 알맞은 문자열과 대조해서 해당하는 값을 전달하기로 했다.
+ 문자열, 시작지점을 함수로 전달하여, 시작지점부터 기존에 정해둔 문자열들의 길이를 이용하여 문자열과 비교하여 알맞은 값을 반환한다.
+ 값을 반환했다면 answer * 10 을 하여 자리를 비우고 값을 더한다.
+ 시작지점의 위치를 알맞은 값의 문자열 길이만큼 증가시켜 중복된 검색을 막았다.

## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
int stringNumToNum(const string str, const int start)
{
    vector<string> numberList = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int i = 0; i < 10; i++)
    {
        string word = numberList[i];
        if(str.compare(start, word.length(), word) == 0)
        {
            return i;
        }
    }
    return -1;   
}
long long solution(string numbers) {
    long long answer = 0;
    int wordLengthList[10] = {4,3,3,5,4,4,3,5,5,4};
    int i = 0;
    while(i < numbers.length())
    {
        long long target = stringNumToNum(numbers,i);
        answer = answer*10 + target;
        if(target == -1) 
            break;
        i += wordLengthList[target];
    }
    return answer;
}
```