// 이상한 문자 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/12930

#include <string>
#include <vector>

using namespace std;

void capitalize(char* c)
{
    if (*c >= 97 && *c <= 122) { *c -= 32; }
}

void lowerlize(char* c)
{
    if (*c >= 65 && *c <= 90) { *c += 32; }
}

string solution(string s) 
{
    const bool even = 0;
    
    int count = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
        {
            count = 0;
            continue;
        }
        
        if (count % 2 == even) { capitalize(&s[i]); }
        else { lowerlize(&s[i]); }
        
        count++;
    }
    
    return s;
}