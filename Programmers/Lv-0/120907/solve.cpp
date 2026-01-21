#include <string>
#include <vector>
#include <iostream>
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

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    int result = 0;
    for(string oper: quiz) 
    {
        string curAnswer = "";
        vector<string> operFom = split(oper,' ');
        switch(operFom[1][0])
        {
            case '+':
                result = stoi(operFom[0]) + stoi(operFom[2]);
                break;
            case '-':
                result = stoi(operFom[0]) - stoi(operFom[2]);
                break;
        }
        curAnswer = result == stoi(operFom[operFom.size()-1])?"O":"X";
        answer.push_back(curAnswer);
    }
    return answer;
}