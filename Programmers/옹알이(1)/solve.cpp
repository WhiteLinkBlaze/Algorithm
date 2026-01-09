#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string targetString[] = {"aya", "ye","woo", "ma"};
    int targetIndex = 0;
    int targetLength = 0;
    bool check = true;
    for(int i = 0; i < babbling.size(); i++)
    {
        check = true;
        for(int j = 0; j < babbling[i].length(); j++)
        {
            switch(babbling[i][j])
            {
                case 'a':
                    targetIndex = 0;
                    break;
                case 'y':
                    targetIndex = 1;
                    break;
                case 'w':
                    targetIndex = 2;
                    break;
                case 'm':
                    targetIndex = 3;
                    break;
                    
            }
            
            targetLength = targetString[targetIndex].length();
            
            if(babbling[i].length() - j >= targetLength && 
                targetString[targetIndex].compare(babbling[i].substr(j,targetLength))==0)
                j+=targetLength-1;
            else
            {
                j = babbling[i].length();
                check = false;
            }
        }
        if (check) answer++;
    }
    return answer;
}