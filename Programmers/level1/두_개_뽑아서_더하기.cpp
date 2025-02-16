// 두 개 뽑아서 더하기
// https://school.programmers.co.kr/learn/courses/30/lessons/68644

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    set<int> answer;
    
    const short length = numbers.size();
    for (int i = 0; i < length; ++i)
    {
        for (int j = i + 1; j < length; ++j)
        {
            answer.insert(numbers[i] + numbers[j]);
        }
    }
    
    return vector<int>(answer.begin(), answer.end());
}