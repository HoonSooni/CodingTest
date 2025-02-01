// 크기가 작은 부분 문자열
// https://school.programmers.co.kr/learn/courses/30/lessons/147355

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) 
{
    int answer = 0;
    
    int subLen = p.size();
    const long long pInt = stoll(p);
    
    for (int i = 0; i <= t.size() - subLen; ++i)
    {
        const long long tInt = stoll(t.substr(i, subLen));

        if (tInt <= pInt) { answer++; }
    }
    
    return answer;
}