// 영어 끝말잇기
// https://school.programmers.co.kr/learn/courses/30/lessons/12981

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_map<string, bool> appeared;
    
    appeared[words[0]] = true;
    for (int i = 1; i < words.size(); ++i)
    {
        vector<int> returning = {(i % n) + 1, (i / n) + 1};
        if (words[i - 1].back() != words[i][0]) return returning;
        
        if (appeared.find(words[i]) == appeared.end()) { appeared[words[i]] = true; }
        else 
        {
            return returning;
        }
    }

    return {0, 0};
}