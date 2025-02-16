// 실패율
// https://school.programmers.co.kr/learn/courses/30/lessons/42889

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

vector<int> solution(int N, vector<int> stages) {
    std::vector<pair<int, double>> failureRates;
    
    for (int stageNum = 1; stageNum <= N; ++stageNum) {
        // counting how many players have reached the current stage
        double reachedButFailedPlayers = 0;
        double reachedPlayers = 0;
        for (int i = 0; i < stages.size(); ++i) {
            if (stages[i] >= stageNum) {
                reachedPlayers++;
                if (stages[i] == stageNum) { reachedButFailedPlayers++; }
            }
        }
        
        // calculating the failure rate
        // number of players who reached the stage but couldn't clear
        // divided by
        // number of players who reached the stage
        double failure = 0;
        if (reachedPlayers > 0) {
            failure = reachedButFailedPlayers / reachedPlayers;
        }
        failureRates.push_back({stageNum, failure});
    }
    
    
    // ordering rates by failure rates in descending order
    sort(failureRates.begin(), failureRates.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        bool comparison = a.second > b.second;
        if (a.second == b.second) { comparison = a.first < b.first; }
        
        return comparison;
    });

    // setting up the returning vector
    vector<int> answer;
    std::transform(failureRates.begin(), failureRates.end(), std::back_inserter(answer), [](const pair<int, double>& p) {
        return p.first;
    });
    
    return answer;
}
