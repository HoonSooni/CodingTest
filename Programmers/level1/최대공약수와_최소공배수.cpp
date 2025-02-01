// 최대공약수와 최소공배수
// https://school.programmers.co.kr/learn/courses/30/lessons/12940

#include <string>
#include <vector>

using namespace std;

int getGCD(int num1, int num2)
{
    while (num2 != 0)
    {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    
    return num1;
}

int getLCM(int num1, int num2)
{
 	return (num1 * num2) / getGCD(num1, num2);   
}

vector<int> solution(int n, int m) 
{
    return vector<int>{getGCD(n, m), getLCM(n, m)};
}