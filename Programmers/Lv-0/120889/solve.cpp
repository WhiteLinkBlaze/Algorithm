#include <string>
#include <vector>

using namespace std;
int maxInVector(vector<int> list, int start, int end)
{
    int max = -1;
    int result = 0;
    for(int i = start; i < end; i++)
    {
        if(max < list[i])
        {
            result = i;
            max = list[i];
        }
    }
    return result;
}
int solution(vector<int> sides) {
    int answer = 0;
    int maxIndex = maxInVector(sides, 0, 3);
    int sumOther = 0;
    for(int i = 0; i < sides.size(); i++)
    {
        if(i == maxIndex)continue;
        sumOther += sides[i];
    }
    answer = sumOther > sides[maxIndex] ? 1 : 2;
    return answer;
}