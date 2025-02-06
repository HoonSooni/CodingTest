// 공원 산책
// https://school.programmers.co.kr/learn/courses/30/lessons/172928

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

// ["SOO","OOO","OOO"]
// ["E 2","S 2","W 1"]

void getPositionBasedOnDirection(
    pair<int, int>& startingPoint,
    const pair<int, int> parkSize,
    const vector<string>& park,
    const unsigned char direction,
    const unsigned int distance) {
    int appliedPosition = 0;
    
    switch (direction) {
        case 'E': {
            appliedPosition = startingPoint.second + distance;
            
            if (appliedPosition >= parkSize.second) { return; }
                
            // for checking if X is between the way
            const string toCheckX = park[startingPoint.first].substr(startingPoint.second, appliedPosition + 1);
            
            if(toCheckX.find('X') != string::npos) { return; }
                
            startingPoint.second += distance;
            
            break;
        }
        case 'W': {
            appliedPosition = startingPoint.second - distance;
            if (appliedPosition < 0) { return; }
                
            const string toCheckX =
                park[startingPoint.first].substr(appliedPosition, startingPoint.second + 1);
            
            if (toCheckX.find('X') != string::npos) { return; }
            
            startingPoint.second -= distance;
            
            break;
        }
        case 'S': {
            appliedPosition = startingPoint.first + distance;
            
            // check if it exceeds the maximum length
            if (appliedPosition >= parkSize.first) {
                return;
            }
            
            // check if there is an obstacle on the way
            for (int i = startingPoint.first; i <= appliedPosition; ++i) {
                if (park[i][startingPoint.second] == 'X') { return; }
            }
            
            startingPoint.first += distance;
            
            break;
        }
        case 'N':
            appliedPosition = startingPoint.first - distance;
                
            // check if it exceeds the maximum length
            if (appliedPosition < 0) {
                return;
            }
            
            // check if there is an obstacle on the way
            for (int i = startingPoint.first; i >= appliedPosition; --i) {
                if (park[i][startingPoint.second] == 'X') { return; }
            }

            startingPoint.first -= distance;
        default:
            return;
    }
}
    
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    pair<int, int> currentPosition;
    
    bool isFound = false;
    for (int i = 0; i < park.size() && !isFound; ++i) {
        for (int j = 0; j < park[i].size(); ++j) {
            if (park[i][j] == 'S') {
                currentPosition.first = i;
                currentPosition.second = j;
                isFound = true;
                break;
            }
        }
    }
    
    for (string& route : routes) {
        const char direction = route[0];
        const unsigned int distance = route[2] - 48;
        
        getPositionBasedOnDirection(currentPosition, {park.size(), park[0].size()}, park, direction, distance);
    }
    
    return {currentPosition.first, currentPosition.second};
}

/*
int main() {
    vector<string> park = {
        "XXX","OOO","OOS"
    };
    
    vector<string> routes = {
        "N 1"
    };
    
    auto result = solution(park, routes);
    cout << result[0] << ' ' << result[1] << endl;
    return 0;
}
*/
