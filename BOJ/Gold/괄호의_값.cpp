// 2504. 괄호의 값
// https://www.acmicpc.net/problem/2504

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int count = 0;
    int temp = 1;
        
    stack<char> st;
    unordered_map<char, int> values = {
        {'(', 2},
        {'[', 3}
    };
    
    string bracketInput;
    cin >> bracketInput;
    
    for (int i = 0; i < bracketInput.size(); ++i) {
        if (values.find(bracketInput[i]) != values.end()) {
            st.push(bracketInput[i]);
            temp *= values[bracketInput[i]];
        } else {
            if (bracketInput[i] == ')') {
                // check the top value
                if (st.empty() || st.top() != '(') { count = 0; break; }
                else {
                    if (bracketInput[i - 1] == '(') { count += temp; }
                    temp /= 2;
                    st.pop();
                }
            } else if (bracketInput[i] == ']') {
                // check the top value
                if (st.empty() || st.top() != '[') { count = 0; break; }
                else {
                    if (bracketInput[i - 1] == '[') { count += temp; }
                    temp /= 3;
                    st.pop();
                }
            }
        }
    }
    
    if (!st.empty()) { count = 0; }
    
    cout << count << "\n";
}
