// [PCCP 기출문제] 1번 / 붕대 감기
// https://school.programmers.co.kr/learn/courses/30/lessons/250137

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    unsigned int seconds = 0;
    unsigned int consecutiveSeconds = 0;
    
    const unsigned int timeToExtraHeal = bandage[0];
    const unsigned int healPerSecond = bandage[1];
    const unsigned int extraHeal = bandage[2];

    int currentHealth = health;
    
    unsigned int attacksIndex = 0;
    while (true) {
        seconds += 1;
        
        // when monster attacks
        if (seconds == attacks[attacksIndex][0]) {
            currentHealth -= attacks[attacksIndex][1];
            
            if (currentHealth <= 0) return -1;
            
            attacksIndex++;
            consecutiveSeconds = 0;
            if (attacksIndex == attacks.size()) { break; }
        } else {
            consecutiveSeconds++;
            
            currentHealth = min(currentHealth + (int)healPerSecond, health);
            
            if (consecutiveSeconds == timeToExtraHeal) {
                currentHealth = min(currentHealth + (int)extraHeal, health);
                consecutiveSeconds = 0;
            }
        }
    }
    
    return currentHealth;
}

/*
int main() {
    cout << solution({1, 1, 1}, 20, {{1, 15}, {5, 16}, {8, 6}}) << endl;
    return 0;
}
*/
