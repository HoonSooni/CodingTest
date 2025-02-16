// 같은 숫자는 싫어
// https://school.programmers.co.kr/learn/courses/30/lessons/12906

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer = {-1};
    
    for (int num : arr)
    {
        if (answer.back() == num) continue;
        else { answer.push_back(num); }
    }

    
    return vector<int>(answer.begin() + 1, answer.end());
}