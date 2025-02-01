// [PCCP_기출문제] 1번 / 동영상 재생기
// https://school.programmers.co.kr/learn/courses/30/lessons/340213

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

unsigned long long convertTimeToDecimal(string time) {
    const size_t colonPos = time.find(':');
    const unsigned int minute = stoi(time.substr(0, colonPos));
    const unsigned int second = stoi(time.substr(colonPos + 1));
    
    return (minute * 60) + second;
}

const string convertDecimaltoTime(unsigned long long decimal) {
    string minute = to_string(decimal / 60);
    string second = to_string(decimal % 60);
    if (minute.size() == 1) { minute = '0' + minute; }
    if (second.size() == 1) { second = '0' + second; }
    
    return minute + ":" + second;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    const unsigned long long videoLen = convertTimeToDecimal(video_len);
    const unsigned long long opStart = convertTimeToDecimal(op_start);
    const unsigned long long opEnd = convertTimeToDecimal(op_end);
    long long position = convertTimeToDecimal(pos);

    for (const string& command : commands) {
        // whenever position is between opening phrase, it goes to the end
        if (opStart <= position && position < opEnd) { position = opEnd; }
        
        if (command == "next") {
            // adding 10 only if position + 10 is not greater than videoLen
            position = ((position + 10) > videoLen) ? videoLen : position + 10;
        } else if (command == "prev") {
            // subtracting 10 only if position - 10 is not smaller than 0 (the minimum)
            position = ((position - 10) < 0) ? 0 : position - 10;
        } else {
            if (opStart <= position && position < opEnd) {
                position = opEnd;
            }
        }
        
        if (opStart <= position && position < opEnd) { position = opEnd; }
    }

    return convertDecimaltoTime(position);
}

/*
int main() {
    cout << solution("10:55", "00:05", "00:15", "06:55", {"prev", "next", "next"}) << endl;
    return 0;
}
*/
