// 피보나치 수
// https://school.programmers.co.kr/learn/courses/30/lessons/12945

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }
    
    return dp[n];
}