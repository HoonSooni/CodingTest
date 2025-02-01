// 콜라츠 추측
// https://school.programmers.co.kr/learn/courses/30/lessons/12943

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) 
{
    int i = 0;
    long long number = num;
    
    while (number != 1)
    {
        if (i >= 500) return -1;
        
        if (number % 2 == 0) { number /= 2; }
        else { number = number * 3 + 1; }
        i++;
    }
    
    return i;
}