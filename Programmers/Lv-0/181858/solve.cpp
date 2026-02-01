#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    bool checkList[100001] = {false,};
    for(int i = 0; i < arr.size() && answer.size() < k; i++)
    {
        if(!checkList[arr[i]])
        {
            answer.push_back(arr[i]);
            checkList[arr[i]] = true;
        }
    }
    while(answer.size() < k)
    {
        answer.push_back(-1);
    }
    return answer;
}