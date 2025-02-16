// 과일 장수
// https://school.programmers.co.kr/learn/courses/30/lessons/135808

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    // sorting the given vector
    sort(score.begin(), score.end(), greater<int>());
    
    // main logic
    for (int i = 0; i + m <= score.size(); i += m) {
        answer += score[i + m - 1] * m;
    }
    
    return answer;
}

/*
int main() {
    cout << solution(4, 3, {4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2}) << endl;
    return 0;
}
*/
