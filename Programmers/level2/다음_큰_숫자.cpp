// 다음 큰 숫자
// https://school.programmers.co.kr/learn/courses/30/lessons/12911

#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int countOne(string binary)
{
    int count = 0;
    for (char digit : binary)
    {
        if (digit == '1') { count++; }
    }
    
    return count;
}

int solution(int n) 
{
    int answer = 0;
    
    string binary = bitset<20>(n).to_string();
    int numOfOnes = countOne(binary);
    
    for (int i = n + 1;; ++i)
    {
        string tempBinary = bitset<20>(i).to_string();
       	int tempNumOfOnes = countOne(tempBinary);
        
        if (numOfOnes == tempNumOfOnes) 
        { 
            answer = i;
            break; 
        }
    }
    
    return answer;
}