// 명예의 전당
// https://school.programmers.co.kr/learn/courses/30/lessons/138477

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;
    
    for (int day = 0; day < score.size(); ++day)
    {
        vector<int> currentScores(score.begin(), score.begin() + day + 1);
        sort(currentScores.begin(), currentScores.end(), greater<int>());
        
        int index = k - 1;
        if (day < k) { index = day; }
        
        answer.push_back(currentScores[index]);
    }
    
    return answer;
}