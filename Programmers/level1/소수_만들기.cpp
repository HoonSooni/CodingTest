// 소수 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/12977

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

bool isPrime(unsigned int num) {
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) { return false; }
    }
    
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    const size_t size = nums.size();
    
    for (int i = 0; i < size - 2; ++i) {
        for (int j = i + 1; j < size - 1; ++j) {
            for (int z = j + 1; z < size; ++z) {
                unsigned int sum = nums[i] + nums[j] + nums[z];
                if (isPrime(sum)) {
                    cout << nums[i] << ' ' << nums[j] << ' ' << nums[z] << endl;
                    answer++;
                }
            }
        }
    }

    return answer;
}

int main() {
    cout << solution({1,2,7,6,4}) << endl;
    return 0;
}
