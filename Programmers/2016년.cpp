// 2016년
// https://school.programmers.co.kr/learn/courses/30/lessons/12901

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

//int days[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//string weeks[8] = { "THU", "FRI", "SAT", "SUN" , "MON", "TUE", "WED" };

string solution(int a, int b)
{
    int days[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string weeks[8] = { "THU", "FRI", "SAT", "SUN" , "MON", "TUE", "WED" };
    
    int totalDays = b;
    if (a != 1) {
        for (int i = 0; i < a - 1; ++i) {
            totalDays += days[i];
        }
    }
    
    return weeks[(totalDays % 7)];
}
/*
int main() {
    // For Testing
//    for (int i = 1; i <= 12; ++i) {
//        for (int j = 1; j <= days[i - 1]; ++j) {
//            cout << i << "월 " << j << " 일: " << solution(i, j) << " | ";
//            if (j % 7 == 0) { cout << endl; }
//        }
//        cout << endl;
//    }
    
    solution(5, 24);
    
    return 0;
}
*/
