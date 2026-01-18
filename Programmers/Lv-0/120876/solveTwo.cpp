#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
bool comparison(vector<int> a, vector<int> b)
{
    if( a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> lines) {
    int answer = 0;
    sort(lines.begin(),lines.end());
    int prev_start = lines[0][0];
    int prev_end = lines[0][1];
    for(int i = 1; i < lines.size(); i++)
    {
        int cur_start = max(prev_start, lines[i][0]);
        int cur_end = min(prev_end, lines[i][1]);
        
        if(cur_start < cur_end)
        {
            answer+=cur_end-cur_start;
            prev_start = cur_end;
            prev_end = max(prev_end, lines[i][1]);
        }
        else
        {
            prev_start = lines[i][0];
            prev_end = lines[i][1];
        }
    }
    return answer;
}