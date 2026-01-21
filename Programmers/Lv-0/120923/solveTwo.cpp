#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int sum = 0;
    int curNum = (total+num-1)/2;
    //init sum
    for(int i = 0; i < num; i++)
    {       
        sum += curNum;
        curNum--;
    }
    //process
    while(sum!=total)
    {
        sum-=(curNum+num);
        sum+=curNum;
        curNum--;
    }
    curNum++;
    //set answer
    for(int i=curNum;i<curNum+num;i++)
        answer.push_back(i);
    
    return answer;
}