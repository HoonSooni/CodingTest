// 수박수박수박수박수박수?
// https://school.programmers.co.kr/learn/courses/30/lessons/12922

#include <string>
#include <vector>

using namespace std;

string solution(int n) 
{
    string answer = "";
    
    const short even = 0;
    const short odd = 1;
    
    for (int i = 0; i < n; ++i)
    {
    	answer += i % 2 == even ? "수" : "박";
    }
    
    return answer;
}