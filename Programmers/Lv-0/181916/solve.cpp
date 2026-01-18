#include <string>
#include <vector>
#include <cmath>

using namespace std;
int square(int a)
{
    return a*a;
}
int solution(int a, int b, int c, int d) {
    int answer = 0;
    int arr[7] = {0,};
    arr[a]++;arr[b]++;arr[c]++;arr[d]++;
    int p = 0, q = 0, r = 0;
    for(int i=6;i>0;i--)
    {
        switch(arr[i])
        {
            case 4:
            case 3:
                p = i;
                break;
            case 2:
                if(p == 0) 
                    p = i;
                else if(q == 0) 
                    q = i;
                break;
            case 1:
                if(q == 0)
                    q = i;
                else
                    r = i;
        }
    }
    if(arr[p] == 4)                     // case 4
        answer = 1111*p;
    else if(arr[p] == 3)                // case 3 1
        answer = square(10*p+q);
    else if(arr[p] == 2 && arr[q] == 2) // case 2 2
        answer = (p+q) * abs(p-q);
    else if(arr[p] == 2 && arr[r] == 1) // case 2 1 1
        answer = q*r;
    else                                // case 1 1 1 1
        answer = r;
    return answer;                          
}