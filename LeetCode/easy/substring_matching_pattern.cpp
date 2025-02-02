// Substring Matching Pattern
// https://leetcode.com/problems/substring-matching-pattern/submissions/1528706964/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        size_t asteriskPos = p.find('*');
        string pLeft = p.substr(0, asteriskPos);
        string pRight = p.substr(asteriskPos + 1);
        
        size_t pLeftPos = s.find(pLeft);
        
        if (pLeftPos != -1) {
            string rightSub = s.substr(pLeftPos + pLeft.size());
            
            size_t pRightPos = rightSub.find(pRight);
            
            if (pRightPos != -1) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    
    const int s = 0;
    const int p = 1;
    
    vector<vector<string>> strings = {
//        {"leetcode", "ee*e"},
//        {"car", "c*v"},
//        {"luck", "u*"},
        {"jjj", "*jj"}
    };
    
    cout << boolalpha;
    
    for (int i = 0; i < strings.size(); ++i) {
        vector<string>& str = strings[i];
        cout << solution.hasMatch(str[s], str[p]) << endl;
    }
    
    
    return 0;
}
