// 914. X of a Kind in a Deck of Cards
// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> occurrences;
        
        for (const int card : deck) {
            occurrences[card]++;
        }
        
        bool isAllSame = true;
        bool isBiggerThanOne = true;
        
        auto firstElement = occurrences.begin();
        const int baseOccurrenceCount = firstElement->second;
        
        // checking the GCD of every occurrence
        int gcdValue = 0;
        for (const pair<int, int> card : occurrences) {
            gcdValue = gcd(gcdValue, card.second);
        }
        
        // if gcd is greater than 2, it means it can have groups having same sizes
        // and the smallest length of a group is greater than 1 at the same time
        return gcdValue >= 2;
    }
};
