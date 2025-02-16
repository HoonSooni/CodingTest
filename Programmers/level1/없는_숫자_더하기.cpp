// 없는 숫자 더하기
// https://school.programmers.co.kr/learn/courses/30/lessons/86051

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) 
{
    int answer = 0;
    
    int sum = 0;
    for (int num : numbers)
    {
        sum += num;
    }
    
    answer = 45 - sum;
    
    return answer;
}