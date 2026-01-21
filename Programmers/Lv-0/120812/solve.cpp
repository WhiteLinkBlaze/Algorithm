#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int memo[1001] = {0,};
    int maxCountIndex = 0;
    int maxIndex = 0;
    int check = true;
    for(int num : array)
    {
        memo[num]++;
        if(maxIndex < num)
            maxIndex = num;
        if(memo[maxCountIndex] < memo[num]) 
        {
            maxCountIndex = num;
        }
    }
    for(int i=1;i<=maxIndex;i++)
    {
        if(maxCountIndex!=i && memo[maxCountIndex]==memo[i])
        {
            check = false;
            break;
        }
    }
    answer = check?maxCountIndex:-1;
    return answer;
}