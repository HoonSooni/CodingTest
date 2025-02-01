// 기사단원의 무기
// https://school.programmers.co.kr/learn/courses/30/lessons/136798

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

const unsigned int getNumOfDivisor(unsigned int number) {
    unsigned int result = 0;
    
    for (unsigned long i = 1; (i * i) <= number; ++i) {
        if (number % i == 0) {
            if ((i * i) == number) { result += 1; }
            else { result += 2; }
        }
    }
    
    return result;
}

int solution(int number, int limit, int power) {
    unsigned int answer = 0;
    
    for (unsigned int knight = 1; knight <= number; ++knight) {
        const unsigned currentKnightPower = getNumOfDivisor(knight);
        
        if (currentKnightPower > limit) { answer += power; }
        else { answer += currentKnightPower; }
    }
    
    return answer;
}

//int main() {
//    cout << "Solution: " << solution(10, 3, 2) << endl;
//    
//    return 0;
//}
