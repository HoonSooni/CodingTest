// 10808. 알바벳 개수
// https://www.acmicpc.net/problem/10808

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

int main() {
    string inputStr;
    vector<int> alphabetCount(26, 0);
    
    cin >> inputStr;
    
    for (const char letter : inputStr) {
        alphabetCount[letter - 'a']++;
    }
    
    for (const int letterCount : alphabetCount) {
        cout << letterCount << ' ';
    }
    
    return 0;
}
