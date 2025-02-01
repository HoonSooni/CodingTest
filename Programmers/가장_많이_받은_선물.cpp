// 가장 많이 받은 선물
// https://school.programmers.co.kr/learn/courses/30/lessons/258712

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    unordered_map<string, int> giftFactor;
    unordered_map<string, unordered_map<string, int>> giftTable;
    
    // initializing tables with default values
    for (string name : friends) {
        giftFactor[name] = 0;
        
        for (string names : friends) {
            if (name != names) {
                giftTable[name][names] = 0;
            }
        }
    }
    
    // inserting actual give exchanging values
    for (string gift : gifts) {
        size_t spacePos = gift.find(' ');
        
        string gaveName = gift.substr(0, spacePos);
        string receivedName = gift.substr(spacePos + 1);
        
        giftFactor[gaveName]++;
        giftFactor[receivedName]--;
        
        giftTable[receivedName][gaveName]++;
    }
    
    unordered_map<string, int> giftScore;
    for (string name : friends) {
        giftScore[name] = 0;
    }
    
    // calculating the result
    for (string receiver : friends) {
        for (auto giver : giftTable[receiver]) {
            int receivedGifts = giver.second;
            int gaveGifts = giftTable[giver.first][receiver];
            
            if (receivedGifts > gaveGifts) {
                giftScore[giver.first]++;
            } else if (receivedGifts < gaveGifts) {
                giftScore[receiver]++;
            } else {
                if (giftFactor[receiver] > giftFactor[giver.first]) { giftScore[receiver]++; }
                else if (giftFactor[giver.first] > giftFactor[receiver]) { giftScore[giver.first]++; }
            }
        }
    }
    
    // get the maximum value
    int max = 0;
    for (auto score : giftScore) {
        if (max < (score.second / 2)) { max = score.second / 2; }
    }
    
    return max;
}

/*
int main() {
    vector<string> names1 = { "muzi", "ryan", "frodo", "neo" };
    vector<string> giftExchanges1 = { "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" };
    
    vector<string> names2 = { "joy", "brad", "alessandro", "conan", "david" };
    vector<string> giftExchanges2 = { "alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david" };
    
    vector<string> names3 = { "a", "b", "c" };
    vector<string> giftExchanges3 = { "a b", "b a", "c a", "a c", "a c", "c a" };
    int result = solution(names1, giftExchanges1);
    
    cout << "result: " << result << endl;
    return 0;
}
*/
