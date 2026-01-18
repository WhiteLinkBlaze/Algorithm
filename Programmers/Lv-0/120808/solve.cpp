#include <string>
#include <vector>
#include <iostream>
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
vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int denominator = denom1*denom2;
    int numerator = numer1*denom2 + numer2*denom1;
    int temp = 0;
    temp = gcd(numerator, denominator);
    numerator = numerator/temp;
	  denominator = denominator/temp;
    answer.push_back(numerator);
    answer.push_back(denominator);
    return answer;
}