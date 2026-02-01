#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(vector<int> query : queries)
    {
        int start = query[0];
        int end = query[1];
        int target = query[2];
        
        int min = 1000001;
        int dummy = -1;
        for(int i = start; i<=end; i++)
        {
            if(target < arr[i] && min > arr[i])
            {
                dummy = arr[i];
                min = arr[i];
            }
        }
        answer.push_back(dummy);
    }
    return answer;
}