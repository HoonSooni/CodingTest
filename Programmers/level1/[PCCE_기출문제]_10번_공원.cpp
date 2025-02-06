// [PCCE 기출문제] 10번 / 공원
// https://school.programmers.co.kr/learn/courses/30/lessons/340198

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    set<int> availableSizes;
    unsigned int max = 0;
    
    for (int i = 0; i < park.size(); ++i) {
        for (int j = 0; j < park[i].size(); ++j) {
            if (park[i][j] != "-1") { continue; }
            else {
                unsigned int size = 1;
                const unsigned int originalI = i;
                const unsigned int originalJ = j;

                bool isExpandable = true;
                while (isExpandable) {
                    // checking the value right next to the last one
                    for (int x = originalI; x < originalI + size; ++x) {
                        if (x < park.size() && originalJ + size < park[0].size()) {
                            if (park[x][originalJ + size] != "-1") {
                                isExpandable = false;
                                break;
                            }
                        } else { isExpandable = false; break; }
                    }
                    
                    if (isExpandable) {
                        // checking the last row
                        for (int x = originalJ; x <= originalJ + size; ++x) {
                            if (originalI + size < park.size() && x < park[0].size()) {
                                if (park[originalI + size][x] != "-1") {
                                    isExpandable = false;
                                    break;
                                }
                            } else { isExpandable = false; break; }
                        }
                        
                        size++;
                    } else {
                        // when isExpandable is false save the maximum value
                        max = max(max, size);
                    }
                }
            }
        }
    }
    
    // sorting mats[] to make the comparison easier
    sort(mats.begin(), mats.end());
    
    // comparing from the biggest value in the mats
    for (int i = mats.size() - 1; i >= 0; --i) {
        if (mats[i] <= max) { return mats[i]; }
    }
    
    return -1;
}

/*
int main() {
    vector<vector<string>> site1 = {
        {"A", "A", "-1", "B", "B", "B", "B", "-1"},
        {"A", "A", "-1", "B", "B", "B", "B", "-1"},
        {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"},
        {"D", "D", "-1", "-1", "-1", "-1", "E", "-1"},
        {"D", "D", "-1", "-1", "-1", "-1", "-1", "F"},
        {"D", "D", "-1", "-1", "-1", "-1", "E", "-1"}
    };
    
    vector<vector<string>> site2 = {
        {"-1", "-1", "A"},
        {"-1", "-1", "-1"},
        {"-1", "-1", "-1"},
    };
    
    vector<vector<string>> site3 = {
        {"-1", "-1", "-1"}
    };
    
    vector<vector<string>> site4 = {
        {"A", "-1"},
        {"-1", "A"}
    };

    vector<vector<string>> site5 = {
        {"A", "-1", "-1"},
        {"-1", "-1", "B"},
        {"-1", "-1", "-1"}
    };
    
    vector<vector<string>> site6 = {
        {{"A"}}
    };
    
    vector<vector<string>> site7 = {
        {"-1", "-1", "-1"},
        {"-1", "-1", "-1"},
        {"-1", "-1", "A"},
    };

    int answer = solution({3}, site7);
    
    cout << "Answer: " << answer << endl;
    return 0;
}
*/
