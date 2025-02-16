// 올바른 괄호
// https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    if (s[0] == ')' || s.size() < 2) return false;
    
    bool answer = true;
    stack<char> st;
    
    for (char p : s)
    {
        if (p == '(') { st.push('('); }
        else 
        {
            if (st.empty() == false && 
                st.top() == '(') { st.pop(); }
            else { return false; }
        }
    }
    
    return st.empty();
}