// 문자열 내림차순으로 배열하기
// 

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) 
{
    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = i + 1; j < s.size(); ++j)
        {
            if (s[i] < s[j]) 
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    
    return s;
}

/*
bool compare(char a, char b)
{
    if (a == b) return false;
    
    return a > b;
}

string solution(string s) 
{
    sort(s.begin(), s.end(), compare);
    
    return s;
}
*/