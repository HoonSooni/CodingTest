// 콜라 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/132267

#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n)
{
    int answer = 0;
    int remainder = 0;
    
    while (n / a >= 1)
    {
        remainder = n % a;
        
        n /= a;
        n *= b;
        answer += n;
        
        n += remainder;
    }
    
    if (n >= a)
    {
        answer += (n / a) * b;
    }

    return answer;
}
