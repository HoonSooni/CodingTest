// 두 정수 사이의 합
// https://school.programmers.co.kr/learn/courses/30/lessons/12912

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    int bigger = (a > b) ? a : b;
    int smaller = (a > b) ? b : a;
    
    for (int i = smaller; i <= bigger; ++i)
    {
        answer += i;
    }
    
    return answer;
}