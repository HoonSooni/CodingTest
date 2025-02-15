// X보다 작은 수
// https://www.acmicpc.net/problem/10871

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int arrayNum = 0, max = 0;
    
    cin >> arrayNum >> max;
    for (int i = 0; i < arrayNum; ++i) {
        int temp = -1;
        cin >> temp;
        
        if (temp < max) { cout << temp << ' '; }
    }
    
    return 0;
}
