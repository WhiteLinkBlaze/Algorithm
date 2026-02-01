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