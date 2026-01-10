#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    int ants[3] = {5,3,1};
    for(int i = 0; i < 3; i++)
    {
        answer += hp/ants[i];
        hp = hp%ants[i];
    }
    
    return answer;
}