#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    string id = id_pw[0];
    string pw = id_pw[1];
    for(vector<string> element : db)
    {
        if(id.compare(element[0]) == 0)
        {
            if(pw.compare(element[1]) == 0)
                answer = "login";
            else
                answer = "wrong pw";
            break;
        }
    }
    if(answer.length() == 0)
        answer = "fail";
    return answer;
}