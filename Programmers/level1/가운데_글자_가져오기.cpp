// 가운데 글자 가져오기
// https://school.programmers.co.kr/learn/courses/30/lessons/12903

#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = "";
    
    const short odd = 1;
    const short even = 0;
    const short half = s.size() / 2;
    if (s.size() % 2 == odd) { return s.substr(half, 1); }
    else 
    {
        return s.substr(half - 1, 2);
    }
}