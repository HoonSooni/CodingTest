// 나누어 떨어지는 숫자 배열
// https://school.programmers.co.kr/learn/courses/30/lessons/12910

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) 
{
    vector<int> answer;
    
    for (int num : arr)
    {
        if (num % divisor == 0) { answer.push_back(num); }
    }
    
    if (answer.size() == 0) { answer.push_back(-1); }
    else { sort(answer.begin(), answer.end()); }
    
    return answer;
}