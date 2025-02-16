// 덧칠하기
// https://school.programmers.co.kr/learn/courses/30/lessons/161989

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

int solution(int n, int m, vector<int> section) {
    int count = 0;
    
    int paintingArea = 0;
    for (int i = 0; i < section.size(); ++i) {
        if (paintingArea <= section[i]) {
            paintingArea = section[i] + m;
            count++;
        }
    }
    
    return count;
}

/*
 int main() {
 return 0;
 }
 */
