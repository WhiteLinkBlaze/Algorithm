#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    int array[201] = {0,};
    int min_start = 300;
    int max_end = -300;
    //init
    for(int i = 0; i < 3; i++)
    {
        int start = lines[i][0] + 100;
        int end = lines[i][1] + 100;
        
        if(min_start > start) min_start = start;
        if(max_end < end) max_end = end;
        
        while(start < end)
        {
            array[start]++;
            start++;
        }
    }
    
    //overlapping line
    while(min_start < max_end)
    {
        if(array[min_start] >= 2)
        {
            for(int i = min_start; array[min_start] == array[i]; i++)
            {
                answer++;
                min_start = i;
            }
        }
        min_start++;
    }
    
    return answer;
}