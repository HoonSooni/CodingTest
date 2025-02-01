// 하샤드 수
// https://school.programmers.co.kr/learn/courses/30/lessons/12947

#include <string>
#include <vector>

using namespace std;

bool solution(int x) 
{
    if (x < 10) return true;
    
    // getting the sum of each digit
    int number = x;
    long sum = 0;
   
    while (number)
    {
        sum += number % 10;
        number /= 10;
    }

    int remain = x % sum;

    return remain == 0 ? true : false;
}