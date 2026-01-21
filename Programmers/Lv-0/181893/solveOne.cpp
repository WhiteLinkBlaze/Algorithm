#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    for(int i=0;i<query.size();i++)
    {
        vector<int>::iterator start,end;
        if(i%2 == 0)
        {
            start = arr.begin() + query[i] + 1;
            end = arr.begin() + arr.size();
        }
        else
        {
            start = arr.begin();
            end = arr.begin()+query[i];
        }
        arr.erase(start,end);
    }
    answer = arr;
    return answer;
}