// N개의 최소공배수
// https://school.programmers.co.kr/learn/courses/30/lessons/12953

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int lcm(int a, int b) 
{
    return a * (b / gcd(a, b));
}

int solution(vector<int> arr) 
{
    int answer = arr[0];
    
    for (int i = 1; i < arr.size(); ++i)
    {
        answer = lcm(answer, arr[i]);
    }
    
    return answer;
}