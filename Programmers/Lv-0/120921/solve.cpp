#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    bool check = false;
    vector<int> start;
    int answerStart =  0;
    int count = 0;
    
    int len = A.length(); //A와 B의 길이는 같고 수정될 일이 없음
    
    //시작 위치 고르기
    for(int i = 0; i < len; i++)
    {
        if(A[0] == B[i])
        {
            start.push_back(i);
        }
    }
    
    //시작 위치를 토대로 검사
    for(int startIndex : start)
    {
        count = 0;
        for(int i = 0; i < len; i++)
        {
            int index = (count+startIndex)%len;
            if(A[i] != B[index])
                break;
            count++;
        }
        if(count == len)
        {
            check = true;
            answerStart = startIndex;
            break;
        }
    }
    answer  = check ? answerStart :-1;
    return answer;
}