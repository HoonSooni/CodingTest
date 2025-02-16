// 모의고사
// https://school.programmers.co.kr/learn/courses/30/lessons/42840

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<int> answers) {
    const vector<unsigned int> student1 = {1, 2, 3, 4, 5};
    const vector<unsigned int> student2 = {2, 1, 2, 3, 2, 4, 2, 5};
    const vector<unsigned int> student3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    const unsigned int length1 = 5;
    const unsigned int length2 = 8;
    const unsigned int length3 = 10;
    
    int answerCount1 = 0;
    int answerCount2 = 0;
    int answerCount3 = 0;
    
    // Calculating Answers
    for (int i = 0; i < answers.size(); ++i) {
        if (student1[i % length1] == answers[i]) { answerCount1++; }
        if (student2[i % length2] == answers[i]) { answerCount2++; }
        if (student3[i % length3] == answers[i]) { answerCount3++; }
    }
    
    // Sorting According to Scores
    vector<pair<int, int>> scores = {{answerCount1, 1}, {answerCount2, 2}, {answerCount3, 3}};
    sort(scores.begin(), scores.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });
    
    // Filtering The Result
    int max = scores[0].first;
    vector<int> result = { scores[0].second };
    for (int i = 1; i < scores.size(); ++i) {
        if (scores[i].first == max) { result.push_back(scores[i].second); }
    }
    
    sort(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> param = {1,2,3,4,5};
    for (int num : solution(param)) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}
