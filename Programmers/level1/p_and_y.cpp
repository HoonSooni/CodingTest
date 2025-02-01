// 문자열 내 p와 y의 개수
// https://school.programmers.co.kr/learn/courses/30/lessons/12916

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int pNum = 0;
    int yNum = 0;

    for (char c : s)
    {
        if (c == 'p' || c == 'P') pNum++;
        else if (c == 'y' || c == 'Y') yNum++; 
    }

    return pNum == yNum;
}