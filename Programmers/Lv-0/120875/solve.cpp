#include <string>
#include <vector>

using namespace std;
double slope(const int x1,const int y1,const int x2,const int y2)
{
    if(x1 > x2)
        return (double)(y1 - y2) / (x1 - x2);
    else
        return (double)(y2 - y1) / (x2 - x1);
}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    vector<double> slopList = vector<double>();
    double tempSlope = 0;
    for(int j = 1; j < dots.size();j++)
    {
        tempSlope = slope(dots[0][0],dots[0][1],dots[j][0],dots[j][1]);
        slopList.push_back(tempSlope);
    }
    for(int j = 1; j < dots.size()-1; j++)
    {
        for(int i = j+1; i < dots.size(); i++)
        {
            tempSlope = slope(dots[j][0],dots[j][1],dots[i][0],dots[i][1]);
            if(slopList.back() == tempSlope) return 1;
            slopList.pop_back();
        }
    }
    return answer;
}