// 10799. 쇠막대기
// https://www.acmicpc.net/problem/10799

#include <bits/stdc++.h>

using namespace std;

// anticipated variables:
// stack<char> brackets

// method:
// loop through the string
// insert stack.push(bracket) if bracket is opening
// when bracket is closing, if there are remaining bracket in a stack, it means that location it has a laser
// when laser is found, the cut stick is the same as the length of the stack.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string input;
    int divisionCount = 0;
    stack<char> brackets;
    
    cin >> input;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '(') { brackets.push(input[i]); }
        else {
            brackets.pop();
            
            if (input[i - 1] == ')') { divisionCount++; }
            else {
                divisionCount += brackets.size();
            }
        }
    }
    
    cout << divisionCount;
}
