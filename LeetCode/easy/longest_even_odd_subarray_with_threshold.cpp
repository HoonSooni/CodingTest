// 2760. Longest Even Odd Subarray With Threshold
// https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/

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
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxLength = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                const int l = i;
                int r = l;
                
                for (; r < nums.size() - 1; ++r) {
                    if (nums[r] % 2 == nums[r + 1] % 2 || nums[r] > threshold) {
                        break;
                    }
                }
                int surplus = nums[r] <= threshold ? 1 : 0;
                maxLength = max(maxLength, r - l + surplus);
                
                i = r;
            }
        }
        
        return maxLength;
    }
};

/*
int main() {
    vector<int> test1 = {3, 2, 5, 4}; // 5, 3
    vector<int> test2 = {1, 2}; // 2, 1
    vector<int> test3 = {2, 3, 4, 5}; // 4, 3
    vector<int> test4 = {1, 1}; // 2, 0
    vector<int> test5 = {1, 2, 3, 4, 5, 6}; // 6, 6
    vector<int> test6 = {2, 3, 4, 5, 6, 7}; // 7, 6
    vector<int> test7 = {2, 2}; // 18, 1

    cout << Solution().longestAlternatingSubarray(test1, 5) << endl; // 3
    cout << Solution().longestAlternatingSubarray(test2, 2) << endl; // 1
    cout << Solution().longestAlternatingSubarray(test3, 4) << endl; // 3
    cout << Solution().longestAlternatingSubarray(test4, 2) << endl; // 0
    cout << Solution().longestAlternatingSubarray(test5, 6) << endl; // 5
    cout << Solution().longestAlternatingSubarray(test6, 7) << endl; // 6
    cout << Solution().longestAlternatingSubarray(test7, 18) << endl; // 1
    return 0;
}
*/
