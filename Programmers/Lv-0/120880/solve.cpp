#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool comparison(pair<int,int> a, pair<int,int>b)
{
    if(a.first == b.first) return a.second > b.second;
    return a.first<b.first;
}
vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<pair<int,int>> numDistanceList;
    for(int i=0; i<numlist.size();i++)
    {
        numDistanceList.push_back(make_pair(abs(numlist[i]-n),numlist[i]));
    }
    sort(numDistanceList.begin(),numDistanceList.end(),comparison);
    for(int i=0; i<numlist.size();i++)
        answer.push_back(numDistanceList[i].second);
    return answer;
}