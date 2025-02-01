// 푸드 파이트 대회
// https://school.programmers.co.kr/learn/courses/30/lessons/134240

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) 
{
    const short even = 0;
    unsigned short finalLength = 1;
    
    // Getting the full length of the answer
    for (int i = 1; i < food.size(); ++i)
    {
        if (food[i] <= 1) { continue; }
        
        if (food[i] % 2 != even) 
        { 
            food[i]--;
        }
        finalLength += food[i];
    }
    
    unsigned short foodNum = 1;
    unsigned short iteration = food[foodNum] / 2;
    unsigned short left = 0, right = finalLength - 1;
    
    vector<unsigned short> answerVec(finalLength);
    while (left < right)
    {
        if (food[foodNum] < 1) { foodNum++; continue; } 
        for (int i = 0; i < iteration; ++i)
        {
            answerVec[left++] = foodNum;
            answerVec[right--] = foodNum;
        }
        foodNum++;
        iteration = food[foodNum] / 2;
    }
    
    string answer = "";
    for (auto num : answerVec)
    {
        answer += to_string(num);
    }
    return answer;
}