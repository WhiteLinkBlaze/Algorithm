#include <string>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a,int b)
{
    int r;
    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

bool finite( const int num)
{
    int target = num;
    for(int i = 2; i <= target; i++)
    {
        if(target%i == 0)
        {
            if(i%5 != 0 && i%2 != 0) return false;
            target/=i;
            i = 1;
        }
    }
    return true;
}
int solution(int a, int b) {
    int answer = 0;
    int commonFactor = gcd(a,b);
    a/=commonFactor;
    b/=commonFactor;
    
    answer = finite(b) ? 1 : 2;
    answer = a%b==0 ? 1 : answer;
    return answer;
}