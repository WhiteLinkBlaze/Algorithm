#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    for(string str : picture)
    {   
        char temp[201] = {0,};
        //k번 반복
        for(int loop_k = 0; loop_k < k; loop_k++)
        {
            //원본 문자열 탐색
            for(int i = 0; i < str.length(); i++)
            {
                //복사
                for(int j = i*k; j < (i+1)*k; j++)
                {
                    temp[j] = str[i];
                }
            }
            answer.push_back(string(temp));
        }
    }
    return answer;
}