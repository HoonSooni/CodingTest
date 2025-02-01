// 시저 암호
// https://school.programmers.co.kr/learn/courses/30/lessons/12926

#include <string>

using namespace std;

string solution(string s, int n) 
{
    string answer = "";
    if (s.size() == 0) { return answer; }
    
    for (unsigned char alphabet : s)
    {
    	if (alphabet == ' ') { answer += alphabet; }
        else 
        {
            unsigned char temp = alphabet + n;
            const bool isLower = (alphabet >= 97 && alphabet <= 122);
            
            if (temp > (isLower ? 122 : 90))  { temp -= 26; }
            answer += temp;
        }
    }
    
    return answer;
}