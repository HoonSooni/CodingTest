// Remove One Element to Make the Array Strictly Increasing
// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/description/

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
    void print(vector<int>& nums) {
        for (int num : nums) {
            cout << num << ' ';
        }
        cout << endl;
    }
    
    bool canBeIncreasing(vector<int>& nums) {
        bool isFound = false;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i - 1] - nums[i] >= 0) {
                if (isFound == true) { return false; }
                
                auto erasePos = nums.begin();
                if ((i == (nums.size() - 1)) || (nums[i + 1] > nums[i - 1])) { erasePos += i; }
                else { erasePos += i - 1;}
                
                nums.erase(erasePos);
                isFound = true;
                
                if (i > nums.size()) { i = nums.size(); }
            }
        }
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) { return false; }
        }

        return true;
    }
};

/*
int main() {
    Solution solution;
    
    vector<vector<int>> numbers = {
        {1, 2, 10, 5, 7},
        {2, 3, 1 ,2},
        {1, 1, 1},
        {10, 1, 2, 3, 4},
        {1, 2, 3, 4, 1},
        {12, 12, 23, 44},
        {12, 12, 12, 23, 44},
        {12, 21, 12},
        {10, 9, 8},
        {5, 4, 3, 2, 5},
        {3, 2, 1, 2, 3, 4},
        {105, 924, 32, 968}
    };
    
    cout << boolalpha;
    
    for (int i = 0; i < numbers.size(); ++i) {
        cout << solution.canBeIncreasing(numbers[i]) << endl;
    }
    
    return 0;
}
*/
