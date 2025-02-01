// 정수 제곱근 판별
// https://school.programmers.co.kr/learn/courses/30/lessons/12934

#include <string>
#include <cmath>

using namespace std;

long long solution(long long n) 
{
    long long answer = -1;
    
    auto squareRoot = sqrt(n);
    if ((long long)squareRoot == squareRoot) 
    { 
        squareRoot += 1;
        answer = squareRoot * squareRoot; 
    }
    
    return answer;
}