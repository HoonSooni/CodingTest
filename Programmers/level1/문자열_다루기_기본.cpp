// 문자열 다루기 기본
// https://school.programmers.co.kr/learn/courses/30/lessons/12918#

#include <string>
#include <vector>

using namespace std;

bool isNumber(char c)
{
    if (c >= 48 && c <= 57) return true;
    else return false;
}

bool solution(string s) 
{
    const short length = s.size();
    
    if (length != 4 && length != 6) return false;
    
    for (char c : s) 
    {
        if (isNumber(c) == false) return false;
    }
    
    return true;
}