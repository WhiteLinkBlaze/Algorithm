#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comparison(pair<int,int> a, pair<int,int> b)
{
    return a.first > b.first;
}
vector<int> solution(vector<vector<int>> score) {
    vector<int> answer = vector<int>(score.size(),1);
    vector<pair<int,int>> averageScore = vector<pair<int,int>>();
    
    for(int i = 0; i < score.size(); i++)
    {
        int eng = score[i][0];
        int math = score[i][1];
        int sum = eng+math;
        averageScore.push_back(make_pair(sum,i));
    }
    sort(averageScore.begin(), averageScore.end(), comparison);
    
    int beforeStudent = averageScore[0].second;
    for(int i = 1; i < averageScore.size(); i++)
    {
        int rank = i+1;
        int curStudent = averageScore[i].second;
        if(score[beforeStudent][0] + score[beforeStudent][1] 
           == score[curStudent][0] + score[curStudent][1])
            rank = answer[beforeStudent];
        answer[curStudent] = rank;
        beforeStudent = curStudent;
    }
    return answer;
}