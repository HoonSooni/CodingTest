// 카드 뭉치
// https://school.programmers.co.kr/learn/courses/30/lessons/159994

#include <iostream>
#include <vector>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer = "Yes";
    
    unsigned int index1 = 0;
    unsigned int index2 = 0;
    for (string word : goal)
    {
        if (index1 < cards1.size() && word == cards1[index1]) { index1++; continue; }
        else if (index2 < cards2.size() && word == cards2[index2]) { index2++; continue; }
        else { answer = "No"; break; }
    }
    
    return answer;
}

/*
int main()
{
    vector<string> cards1 = {"i", "drink", "water"};
    vector<string> cards2 = {"want", "to"};
    vector<string> goal = {"i", "want", "to", "drink", "water"};

    cout << solution(cards1, cards2, goal) << endl;
    
    return 0;
}
*/
