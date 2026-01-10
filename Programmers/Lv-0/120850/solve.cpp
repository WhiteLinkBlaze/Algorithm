#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    vector<int> list = vector<int>(10,0);
    //extract number
    for(int i = 0; i < my_string.length(); i++)
    {
        if(my_string[i] - '0' < 10 && my_string[i] - '0' >= 0)
            list[my_string[i]-'0']++;
    }
    //insert number
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < list[i];j++) 
            answer.push_back(i);
    }
    return answer;
}