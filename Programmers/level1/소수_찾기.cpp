#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int solution(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int num = 2; num * num <= n; ++num) {
        if (isPrime[num]) {
            for (int power = num * num; power <= n; power += num) {
                isPrime[power] = false; // num's multiples are not prime
            }
        }
    }
    
    unsigned int answer = 0;
    for (bool prime : isPrime) {
        if (prime) { answer++; }
    }
    return answer;
}

int main() {
    return 0;
}
