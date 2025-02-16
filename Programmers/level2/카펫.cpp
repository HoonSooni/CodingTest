// 카펫
// https://school.programmers.co.kr/learn/courses/30/lessons/42842

#include <iostream>
#include <vector>

using namespace std;

const short even = 0;
vector<int> solution(int brown, int yellow)
{
    int total = brown + yellow;

    for (int i = 1; i <= total; ++i)
    {
        if (total % i == even) 
        { 
            int width = total / i;

            if (width >= i)
            {
                if ((width - 2) * (i - 2) == yellow) 
                {
                    return {width, i};
                }
            }
        }
    }
    
    return {total};
}

/* 반례 몇 개가 틀림 (너무 단순하게 생각함)
const short even = 0;
const short odd = 1;

vector<int> solution(int brown, int yellow) 
{
    const int sum = brown + yellow;
    vector<int> factors;
    
    for (int i = 1; i <= sum; ++i)
    {
        if (sum % i == 0) { factors.push_back(i); }
    }
    
    const short factorSize = factors.size();
    const short halfPoint = factorSize / 2;
    vector<int> answer(2);
    
    if (factorSize % 2 == even)
    {
        answer[0] = factors[halfPoint];
        answer[1] = factors[halfPoint - 1];
    }
    else 
    {
        answer[0] = factors[halfPoint];
        answer[1] = factors[halfPoint];
    }
    
    return answer;
}
*/
