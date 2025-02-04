// 신고 결과 받기
// https://school.programmers.co.kr/learn/courses/30/lessons/92334

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

// ["muzi", "frodo", "apeach", "neo"]
// ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
// k: 2

// "muzi"      ["frodo", "neo"]     ["frodo", "neo"]
// "frodo"     ["neo"]              ["neo"]
// "apeach"    ["muzi", "frodo"]    ["frodo"]
// "neo"       없음                  없음

pair<string, string> divideNamesBySpace(string names) {
    const size_t spacePos = names.find(' ');
    const string reporter = names.substr(0, spacePos);
    const string accused = names.substr(spacePos + 1);
    
    return make_pair(reporter, accused);
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 1. using a map to store who reported who
    // 2. it needs two maps: 1. storing who reported, 2. how many accused
    
    // using set because more than 1 report is not meaningful in this problem
    unordered_map<string, unordered_set<string>> reportRecord;
    unordered_map<string, int> reportCount;
    
    // storing values accordingly
    for (string record : report) {
        auto [reporter, accused] = divideNamesBySpace(record);
        
        // when a person already reported someone,
        // it should not be counted
        unordered_set<string>& tempReportedSet = reportRecord[reporter];
        if (tempReportedSet.find(accused) == tempReportedSet.end()) {
            reportCount[accused]++; // adding reportCount for who got reported
        }
        reportRecord[reporter].insert(accused);
    }
    
    // calculating how many email should each of them get
    vector<int> emailCount(id_list.size());
    
    for (int i = 0; i < id_list.size(); ++i) {
        const string& name = id_list[i];
        
        for (string accused : reportRecord[name]) {
            if (reportCount[accused] >= k) { emailCount[i]++; }
        }
    }
    
    return emailCount;
}

/*
int main() {
    solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"}, 3);
    
    return 0;
}
*/
