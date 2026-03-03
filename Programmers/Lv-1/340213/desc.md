# [[PCCP 기출문제] 1번 / 동영상 재생기](https://school.programmers.co.kr/learn/courses/30/lessons/340213)
## 풀이
구현 문제임
+ 시간 문자열을 계산하기 쉽도록 int 형으로 변환
+ 현재 시간이 스킵 구간이면 스킵 구간의 마지막 값을 대입
+ prev면 10을 빼고, 동영상의 구간은 0 ~ video_len이기 때문에  음수가 되면 0을 대입
+ next면 10을 더하고, 동영상의 구간은 0 ~ video_len이기 때문에  video_len보다 크면 cnv_video_len을 대입
+ 마지막으로 스킵 구간이면 스킵 구간의 마지막 값을 대입
+ int형으로 변환했던 값을 다시 시간 문자열 값으로 변환하여 반환
## 코드
```cpp
#include <string>
#include <vector>

using namespace std;
int convert_str_time_to_int(string str)
{
    if(str.length() < 5) return 0;
    return stoi(str.substr(0,2))*60 + stoi(str.substr(3,2));
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int cnv_video_len = convert_str_time_to_int(video_len);
    int cnv_pos = convert_str_time_to_int(pos);
    int cnv_op_start = convert_str_time_to_int(op_start);
    int cnv_op_end = convert_str_time_to_int(op_end);
    
    for(int i = 0; i < commands.size(); i++){
        string oper = commands[i];
        //opening skip
        if(cnv_pos<cnv_op_end && cnv_pos >= cnv_op_start) cnv_pos = cnv_op_end;
        
        //operation commands
        if(oper.compare("prev") == 0){
            cnv_pos -= 10;
            if(cnv_pos < 0) cnv_pos = 0;
        }
        else if(oper.compare("next") == 0)
        {
            cnv_pos += 10;
            if(cnv_pos > cnv_video_len) cnv_pos = cnv_video_len;
        }
    }
    //opening skip
    if(cnv_pos<cnv_op_end && cnv_pos >= cnv_op_start) cnv_pos = cnv_op_end;
    //convert time
    answer = 
        (cnv_pos/60 < 10 ? "0":"")+ to_string(cnv_pos/60) 
        + ":"
        + (cnv_pos%60 < 10 ? "0":"")+ to_string(cnv_pos%60);
    return answer;
}
```