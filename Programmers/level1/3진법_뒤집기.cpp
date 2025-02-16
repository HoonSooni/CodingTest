// 3진법 뒤집기
// https://school.programmers.co.kr/learn/courses/30/lessons/68935

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    vector<int> ternary = {};
    
    while (n > 0)
    {
        ternary.push_back(n % 3);
        n /= 3;
    }
    
    int power = 0;
    for (int i = ternary.size() - 1; i >= 0; --i)
    {
        answer += ternary[i] * pow(3, power++);
    }
    
    return answer;
}