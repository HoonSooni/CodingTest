#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;

    for (int num = 0; num <= n; ++num)
    {
        // answer += num ? num % n == 0 : 0;
        if (n % num == 0) 
        {
            answer += num;
            cout << answer << endl;;
        }
    }

    return answer;
}