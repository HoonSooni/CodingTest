// JadenCase 문자열 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/12951

#include <iostream>
#include <string>
#include <vector>
#include <cctype> 

using namespace std;

string solution(string s) 
{
    string answer = "";
    
    
    int from = 0;
    string word = "";
    
    for (int i = 0; i <= s.size(); ++i)
    {
        if (s[i] == ' ' || i == s.size()) 
        { 
            word = s.substr(from, i - from); 
            cout << word << endl;
            from = i + 1;
            
            word[0] = toupper(word[0]);
            for (int j = 1; j < word.size(); ++j)
            {
                word[j] = tolower(word[j]);
            }
            answer += word + ' ';
        }
    }
    
    answer.pop_back();
    return answer;
}