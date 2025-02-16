// 짝지어_제거하기
// https://school.programmers.co.kr/learn/courses/30/lessons/12973

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    
    for(int i = 0; i < s.size(); ++i)
    {
        char character = s[i];
        if (st.empty() == false && st.top() == character) 
        {
            st.pop();
        }
        else 
        {
        	st.push(character);
        }
    }
    
    return st.empty() ? 1 : 0;
}

/* 시간 초과 코드
int solution(string s)
{
    short odd = 1;
    if (s.size() % 2 == odd) { return 0; }
    
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == s[i + 1]) 
        { 
            s.erase(i, 2); 
            i = 0; continue;
        }
        i += 1;
    }

    return s.size() == 0 ? 1 : 0;  
} 
*/