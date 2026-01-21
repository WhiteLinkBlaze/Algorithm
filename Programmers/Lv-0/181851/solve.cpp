#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comparison(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}
int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    vector<pair<int,int>> sortedRank;
    for(int i=0; i<rank.size();i++)
    {
        if(attendance[i])
            sortedRank.push_back(make_pair(rank[i],i));
    }
    sort(sortedRank.begin(), sortedRank.end(),comparison);
    answer = 10000*sortedRank[0].second + 100*sortedRank[1].second+sortedRank[2].second;
    return answer;
}