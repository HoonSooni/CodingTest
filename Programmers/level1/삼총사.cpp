// 삼총사
// https://school.programmers.co.kr/learn/courses/30/lessons/131705

#include <vector>

using namespace std;

unsigned int answer = 0;

void DFS(
    const vector<int>& number, 
    unsigned int index, 
    unsigned int count, 
    unsigned int sum)
{
    if (count == 3)
    {
        if (sum == 0) { answer++; return; }
    }
    
    if (index >= number.size()) { return; }
    
    DFS(number, index + 1, count + 1, sum + number[index]);
    DFS(number, index + 1, count, sum);
}

int solution(vector<int> number)
{
    DFS(number, 0, 0, 0);
    return answer;
}