// 최댓값과 최솟값
// https://school.programmers.co.kr/learn/courses/30/lessons/12939

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <climits>

using namespace std;

string solution(string s) 
{
    istringstream iss(s); 
    string stringNum;
    
    int max = INT_MIN;
    int min = INT_MAX;
    
    while (iss >> stringNum)
    {
        int num = stoi(stringNum);
        
        if (max < num) { max = num; }
        if (min > num) { min = num; }
    }
    
    return to_string(min) + " " + to_string(max);
}