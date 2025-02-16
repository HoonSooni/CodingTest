// 폰켓몬
// https://school.programmers.co.kr/learn/courses/30/lessons/1845

#include <algorithm>
#include <iostream>
#include <vector>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    const size_t maximum = nums.size() / 2;
    set<int> s(nums.begin(), nums.end());
    
    return s.size() > maximum ? maximum : s.size();
}

/*
int main()
{
    vector<int> nums = {3,3,3,2,2,4};
    
    cout << solution(nums) << endl;
    
    return 0;
}
*/
