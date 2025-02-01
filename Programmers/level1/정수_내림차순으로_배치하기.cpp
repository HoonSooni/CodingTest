// 정수 내림차순으로 배치하기
// https://school.programmers.co.kr/learn/courses/30/lessons/12933

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) 
{
    long long answer = 0;

    vector<short> numbers;

    while (n > 0)
    {
        short lastDigit = n % 10;
        n /= 10;

        numbers.push_back(lastDigit);
    }

    sort(numbers.begin(), numbers.end(), greater<int>());

    for (short num : numbers)
    {
        answer += num;
        answer *= 10;
    }

    return answer / 10;
}