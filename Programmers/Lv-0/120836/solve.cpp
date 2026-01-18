#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int max = (int)floor(sqrt(n));
    for(int i=1; i <= max; i++)
    {
        if(n%i == 0)
            answer++;
    }
    
    if(n == max*max) answer = answer + (answer-1);
    else answer *=2;
    return answer;
}