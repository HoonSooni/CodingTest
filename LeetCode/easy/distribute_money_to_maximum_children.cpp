// Distribute Money to Maximum Children
// https://leetcode.com/problems/distribute-money-to-maximum-children/description/

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
    int distMoney(int money, int children) {
        // if it's impossible to distribute
        if (money < children) { return -1; }
        
        if (money > children * 8) { return children - 1; }
        
        int remainedMoney = money - children;
        if (remainedMoney < 7) { return 0; }
        
        int count = 0;
        while (remainedMoney >= 7) {
            remainedMoney -= 7;
            children--;
            count++;
        }
        
        if (remainedMoney == 0) { return count; }
        else if ((children == 0 && remainedMoney > 0) || (children == 1 && remainedMoney == 3)) { return count - 1;}
        
        return count;
    }
};

/*
int main() {
    int testcases[][3] = {
        {1, 2, 0},
        {20, 3, 1},
        {16, 2, 2},
    };
    
    Solution solution;
    
    for (int i = 0; i < 4; ++i) {
        cout <<
            "Money: " << testcases[i][0] <<
            " Children: " << testcases[i][1] <<
            " Result: " << solution.distMoney(testcases[i][0], testcases[i][1]) <<
            " Expected Result: " << testcases[i][2] << endl;
    }
    return 0;
}
*/
