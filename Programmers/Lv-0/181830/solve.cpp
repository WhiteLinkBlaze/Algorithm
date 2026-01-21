#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    int col = arr[0].size();
    int row = arr.size();
    while(row > col)
    {
        for(int i=0;i<row; i++)
        {
            arr[i].push_back(0);
        }
        col = arr[0].size();
    }
    while( col > row)
    {
        arr.push_back(vector<int>(col,0));
        row = arr.size();
    }
    answer = arr;
    return answer;
}