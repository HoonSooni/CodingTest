// 숫자 문자열과 영단어
// https://school.programmers.co.kr/learn/courses/30/lessons/81301

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool isNumber(char c)
{
    return (c >= 48 && c <= 57);
}

void increaseAnswer(int& answer, int adder)
{
    answer += adder;
    answer *= 10;
}

int solution(string s) 
{
    int answer = 0;
    unordered_map<char, pair<int, int>> lengthOfNumbers =
    {
        {'z', {4, 0}},
        {'o', {3, 1}},
        {'e', {5, 8}},
        {'n', {4, 9}}
    };
    
    int letterCount = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        cout << c << endl;
        if (isNumber(c) == true) { increaseAnswer(answer, c - 48); }
        else
        {
            unsigned short jump = 0;
            unsigned short adder = 0;
            if (c == 't') 
            {
                if (s[i + 1] == 'w') { adder = 2; jump = 3; }
                else { adder = 3; jump = 5; }
            }
            else if (c == 's')
            {
                if (s[i + 1] == 'i') { adder = 6; jump = 3; }
                else { adder = 7; jump = 5; }
            }
            else if (c == 'f')
            {
                if (s[i + 1] == 'o') { adder = 4; jump = 4; }
                else { adder = 5; jump = 4; }
            }
            else
            {
                jump = lengthOfNumbers[c].first;
                adder = lengthOfNumbers[c].second;
            }
            
            increaseAnswer(answer, adder);
            i += jump - 1;
        }
    }
     
    return answer / 10;
}