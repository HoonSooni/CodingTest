// 핸드폰 번호 가리기
// https://school.programmers.co.kr/learn/courses/30/lessons/12948

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) 
{
    int size = phone_number.size();
    
    for (int i = 0; i < size - 4; ++i)
    {
        phone_number[i] = '*';
    }
    
    return phone_number;
}