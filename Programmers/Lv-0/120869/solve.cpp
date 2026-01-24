#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    for(string elementDic : dic)
    {
        int count = 0;
        for(string spellTxt: spell)
        {
            //사전의 단어에 원하는 단어가 있는가
            if(elementDic.find(spellTxt) != string::npos)
                count++;
            else
                break;
        }
        //단어가 전부 들어가 있었는가
        if(count == spell.size())
        {
            answer = 1;
            break;
        }
    }
    
    return answer;
}