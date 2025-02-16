// 예산
// https://school.programmers.co.kr/learn/courses/30/lessons/12982

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) 
{
    int answer = 0;
    
    sort(d.begin(), d.end());
    
    for (int request : d)
    {
        if (budget >= request) 
        {
            budget -= request;
            answer++;
        }
    }
    
    return answer;
}