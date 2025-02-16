// 음양 더하기
// https://school.programmers.co.kr/learn/courses/30/lessons/76501

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) 
{
    int answer = 0;
 	
    for (int i = 0; i < signs.size(); ++i)
    {
        bool sign = signs[i];
        int number = absolutes[i];
        
        if (sign == true) { answer += number; }
        else { answer -= number; }
    }
    
    return answer;
}