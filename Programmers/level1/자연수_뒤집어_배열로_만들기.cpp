// 자연수 뒤집어 배열로 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/12932

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) 
{
    vector<int> answer;

    while (n > 0)
    {
        short lastDigit = n % 10;
        n /= 10;
        answer.push_back(lastDigit);
    }
    
    return answer;
}