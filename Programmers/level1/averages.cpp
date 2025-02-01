// 평균 구하기
// https://school.programmers.co.kr/learn/courses/30/lessons/12944

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) 
{
    double answer = 0;

    for (int num : arr) 
    {
        answer += num;
    }

    return answer / arr.size();
}