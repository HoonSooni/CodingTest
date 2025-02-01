// 약수의 개수와 덧셈
// https://school.programmers.co.kr/learn/courses/30/lessons/77884

#include <string>
#include <vector>

using namespace std;

int countFactors(int number)
{
    if (number == 1) return 1;
    
    int count = 1;
    
    for (int i = 2; i < number; ++i)
    {
        if (number % i == 0) count++;
    }
    
    return count + 1;
}

int solution(int left, int right) 
{
    int answer = 0;
    
    for (int i = left; i <= right; ++i)
    {
        if (countFactors(i) % 2 == 0) answer += i;
        else answer -= i;
    }
    
    return answer;
}