// 문자열을 정수로 바꾸기
// https://school.programmers.co.kr/learn/courses/30/lessons/12925

#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = 0;

    char firstLetter = s[0];

    int i = 0;
    int isNegative = false;
    if ((firstLetter >= 48 && firstLetter <= 57) == false) 
    {
        if (firstLetter == '-') isNegative = true;
        i++;
    }

    for (; i < s.size(); ++i)
    {
        answer += s[i] - 48;
        answer *= 10;
    }
    answer /= 10;
    
    if (isNegative == true)
    {
        answer *= -1;
    }

    return answer;
}