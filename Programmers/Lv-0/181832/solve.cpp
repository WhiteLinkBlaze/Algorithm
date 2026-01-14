#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer = vector<vector<int>>(n , vector<int>(n,0));
    int num = 1;
    int count = 0;
    int x = 0, y = 0;
    while(num <= n*n)
    {
        //x증가
        while(x < n - count)
        {
            answer[y][x++] = num++;
        }
        x--;
        y++;
        //y증가
        while(y < n - count)
        {
            answer[y++][x] = num++;
        }
        y--;
        x--;
        //x감소
        while(x >= count)
        {
            answer[y][x--] = num++;
        }
        x++;
        y--;
        //y감소
        while(y > count)
        {
            answer[y--][x] = num++;
        }
        x++;
        y++;
        count++;
    }
    return answer;
}