// 문자열 내 마음대로 정렬하기
// https://school.programmers.co.kr/learn/courses/30/lessons/12915

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num = 0;

bool compare(string a, string b) {
    if (a[num] == b[num]) {
        return a < b;
    }
    
    return a[num] < b[num];
}

vector<string> solution(vector<string> vec, int n) {
    num = n;
    
    std::sort(vec.begin(), vec.end(), compare);

    return vec;
}