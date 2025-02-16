// 이진 변환 반복하기
// https://school.programmers.co.kr/learn/courses/30/lessons/70129

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) 
{
    int iteration = 0;
    int removedZeros = 0;
    
    while (s.size() > 1) 
    {
        // getting how many zeros are in s
        int zeros = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '0') { zeros++; }
        }
        int lengthOfOnes = s.size() - zeros;
        
        string binary = "";
        // turning the length of ones into binary form
        while (lengthOfOnes > 0) 
        {
            binary += (lengthOfOnes % 2) + 48;
            lengthOfOnes /= 2;
        }
        
        cout << binary << endl;
        
        s = binary;
        removedZeros += zeros;
        iteration++;
    }
    
    return vector<int>{iteration, removedZeros};
}