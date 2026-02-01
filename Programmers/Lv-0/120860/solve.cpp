#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    int x = dots[0][0];
    int y = dots[0][1];
    int x_lineLength = 0;
    int y_lineLength = 0;
    for(int i = 1; i < dots.size(); i++)
    {
        if(x == dots[i][0])
        {
            y_lineLength = y - dots[i][1];
        }
        if(y == dots[i][1])
        {
            x_lineLength = x - dots[i][0];
        }
    }
    x_lineLength *= x_lineLength < 0 ? -1 : 1;
    y_lineLength *= y_lineLength < 0 ? -1 : 1;
    answer = x_lineLength * y_lineLength;
    return answer;
}