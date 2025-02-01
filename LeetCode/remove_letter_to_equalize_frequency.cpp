// Remove Letter to Equalize Frequency
// https://leetcode.com/problems/remove-letter-to-equalize-frequency/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> checker;
        
        // Count the frequency of each character
        for (const char letter : word) {
            checker[letter]++;
        }
        
        // Create a frequency map
        unordered_map<int, int> freqCount;
        for (const auto& pair : checker) {
            freqCount[pair.second]++;
        }
        
        // If there's only one character, we can always remove it
        if (freqCount.size() == 1) {
            int freq = freqCount.begin()->first;
            // If the frequency is 1, we can remove any character
            if (freq == 1) return true;
            // If all characters have the same frequency > 1, we can remove one character
            if (checker.size() == 1) return true;
        }
        
        // If there are more than 2 different frequencies, it's impossible
        if (freqCount.size() != 2) {
            return false;
        }
        
        // Get the two frequencies
        auto it = freqCount.begin();
        int freq1 = it->first;
        int count1 = it->second;
        it++;
        int freq2 = it->first;
        int count2 = it->second;
        
        // Case 1: One character has a frequency of 1, and the rest have the same frequency
        if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) {
            return true;
        }
        
        // Case 2: One character has a frequency that is one more than the others
        if ((freq1 - freq2 == 1 && count1 == 1) || (freq2 - freq1 == 1 && count2 == 1)) {
            return true;
        }
        
        return false;
    }
};
