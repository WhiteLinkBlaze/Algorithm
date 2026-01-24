#include <string>
#include <vector>

using namespace std;
vector<string> split(string sentence, char deli)
{
    vector<string> dummy;
    int base=0,next=0;
    while((next = sentence.find(deli,base))!=string::npos)
    {
        int len = next - base;
        dummy.push_back(sentence.substr(base,len));
        base = next + 1;
    }
    dummy.push_back(sentence.substr(base,next-base));
    return dummy;
    
}

string solution(string polynomial) {
    string answer = "";
    int x = 0;
    int number = 0;
    vector<string> str = split(polynomial, ' ');
    for(int i=0; i<str.size();i++)
    {
        char lastWord = str[i][str[i].length()-1];
        if(lastWord == 'x')
        {
            //stoi 함수 사용시 해당 문자열에 숫자가 없으면 core dump 일어남
            x += str[i][0] == 'x' ? 1 : stoi(str[i]);
        }
        else if(str[i].compare("+") == 0)
            continue;
        else
            number += stoi(str[i]);
    }
    
    string xString = x > 1 ? to_string(x)+"x" : "x";
    string numString = to_string(number);
    
    if(x!=0)
        answer+=xString;
    if(answer.length() != 0 && number != 0)
        answer+=" + ";
    if(number != 0) 
        answer += numString;
    
    return answer;
}