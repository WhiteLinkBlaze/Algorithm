#include <string>
#include <vector>

using namespace std;

bool findThree(int n)
{
    string nString = to_string(n);
    if(nString.find('3') != string::npos)
        return true;
    return false;
}
int solution(int n) {
    int answer = 0;
    int offset = 0;
    
    for(int i = 1; i <= n; i++)
    {
        int result = i + offset;
        while(findThree(result) || result % 3 == 0)
        {
            offset++;
            result++;
        }
        answer = result;
    }
    return answer;
}