// Can Place Flowers
// https://leetcode.com/problems/can-place-flowers/description/

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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) { return true; }
        
        for (int i = 0; i < flowerbed.size(); ++i) {
            // if it is already planted
            if (flowerbed[i] == 1) { continue; }
            else {
                // checking left and right
                bool isLeftEmpty = i == 0 || flowerbed[i - 1] == 0;
                bool isRightEmpty = i == flowerbed.size() - 1 || flowerbed[i + 1] == 0;
                
                // if both are okay, then change it to 1 as a sign of occupying
                if (isLeftEmpty && isRightEmpty) {
                    flowerbed[i] = 1;
                    
                    // decreasing n whenever planting has done successfully
                    n--;
                    if (n == 0) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

/*
int main() {
    vector<int> flowerbed1 = {1, 0, 0, 0, 0};
    vector<int> flowerbed3 = {1, 0, 1, 0, 0, 1};
    vector<int> flowerbed4 = {1, 0, 1, 0, 1, 0, 1};
    vector<int> flowerbed5 = {0, 0, 1, 0, 1};
    vector<int> flowerbed6 = {1, 0, 0, 0, 0, 0, 1};
    vector<int> flowerbed7 = {1, 0, 0, 0, 1, 0, 0};
    vector<int> flowerbed8 = {1, 0};

    cout << boolalpha;
    cout << Solution().canPlaceFlowers(flowerbed8, 1) << endl;
    return 0;
}
*/
