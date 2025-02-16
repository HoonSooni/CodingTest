// 최소직사각형
// https://school.programmers.co.kr/learn/courses/30/lessons/86491

#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    unsigned short leftMax = 0;
    unsigned short rightMax = 0;
    
    for (int i = 0; i < sizes.size(); ++i)
    {
        int& left = sizes[i][0];
        int& right = sizes[i][1];
        if (left < right) 
        {
            unsigned short temp = left;
            left = right;
            right = temp;
        }
        
        if (leftMax < left) { leftMax = left; }
        if (rightMax < right) { rightMax = right; }
    }
    
    return leftMax * rightMax;
}