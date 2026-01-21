#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    bool bits[6] = {false,};
    int bitLimit = (int) log10((double)r)+1;
    int bitStart = (int) log10((double)l);
    bits[bitStart] = true;
    int limit = pow(2,bitLimit) - pow(2,bitStart);
    for(int k=0;k<limit;k++)
    {
        int num = 0;
        for(int i=0; i<bitLimit; i++)
        {
            if(bits[i])
                num += 5*pow(10,i);
        }
        bool check = true;
        int index = 0;
        while(check)
        {
            bits[index] = !bits[index];
            if(!bits[index])
                index++;
            else
                check = !check;
            if(index == bitLimit) break;
        }
        if(l <= num && num <=r)
            answer.push_back(num);
    }
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}