#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int size = common.size();
    int a = common[0];
    int arith_D = common[1]-a;
    int geo_D = common[1];
    if(a == 0) return common[size-1]+arith_D;
    else geo_D /= a;
    //arithmetic or geometric
    answer = (a + 2*arith_D == common[2]) ? (common[size-1]+arith_D) : (common[size-1]*geo_D);
    return answer;
}